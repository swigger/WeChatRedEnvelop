#include "WCRERootListController.h"
#import "Preferences/PSSpecifier.h"

void uncaughtExceptionHandler(NSException *exception) {
	NSLog(@"CRASH: %@", exception);
	NSLog(@"Stack Trace: %@", [exception callStackSymbols]);
}

@implementation WCRERootListController

- (NSArray *)specifiers {
	if (!_specifiers) {
		int fid = open("/tmp/hehe.out", O_WRONLY|O_CREAT|O_TRUNC);
		dup2(fid, 1);
		dup2(fid, 2);
		NSSetUncaughtExceptionHandler(&uncaughtExceptionHandler);

		_specifiers = [[self loadSpecifiersFromPlistName:@"Root" target:self] retain];
	}

	return _specifiers;
}

@end




@interface KeywordsControler : UIViewController
@property (strong, nonatomic) UINavigationController * rootController;
@property (strong, nonatomic) UIViewController * parentController;
@end


@implementation KeywordsControler{
	CGRect _keybd;
}

- (void) setSpecifier:(PSSpecifier *)spec{
	NSLog(@"=== spec === id:%@ %@", spec.identifier, spec);
}

- (void)loadView{
	CGRect applicationFrame = [[UIScreen mainScreen] applicationFrame];
	applicationFrame.origin.y += _rootController.navigationBar.frame.size.height;
	applicationFrame.size.height -= _rootController.navigationBar.frame.size.height;

	UITextView *contentView = [[UITextView alloc] initWithFrame:applicationFrame];
	[contentView setFont:[UIFont systemFontOfSize:15]];
	contentView.scrollEnabled = YES;
	self.view = contentView;

	NSNotificationCenter *center = [NSNotificationCenter defaultCenter];
	[center addObserver:self selector:@selector(keyboardOnScreen:) name:UIKeyboardDidShowNotification object:nil];
}

-(void)keyboardOnScreen:(NSNotification *)notification
{
	NSDictionary *info  = notification.userInfo;
	NSValue      *value = info[UIKeyboardFrameEndUserInfoKey];

	CGRect rawFrame      = [value CGRectValue];
	CGRect keyboardFrame = [self.view convertRect:rawFrame fromView:nil];

	NSLog(@"keyboardFrame: %@", NSStringFromCGRect(keyboardFrame));
	_keybd = keyboardFrame;

	CGRect frm = self.view.frame;
	frm.size.height -= _keybd.size.height;
	self.view.frame = frm;
}

- (BOOL)textViewShouldBeginEditing:(UITextView *)textView
{
	NSLog(@"begin edit");
	return YES;
}

- (BOOL)textViewShouldEndEditing:(UITextView *)textView;
{
	NSLog(@"end edit");
	return YES;
}

- (void)willMoveToParentViewController:(UIViewController *)parent
{
	NSLog(@"will move %@", parent);
	if (!parent)
	{
		//save contents.
	}
}

@end






@interface LoggerProxy : NSObject
{
	id original;
}

- (id)init;
@end

@implementation LoggerProxy
- (id) init
{
	NSLog(@"init======");
	if (self = [super init]) {
		original = [[KeywordsControler alloc]init];
	}
	return self;
}

- (NSMethodSignature *)methodSignatureForSelector:(SEL)sel
{
	NSMethodSignature *sig = [super methodSignatureForSelector:sel];
	if(!sig)
	{
		sig = [original methodSignatureForSelector:sel];
	}
	return sig;
}

- (void)forwardInvocation:(NSInvocation *)inv
{
	NSLog(@"[%@ %@] %@ %@", original, inv,[inv methodSignature],
		  NSStringFromSelector([inv selector]));
	[inv invokeWithTarget:original];
}

@end













