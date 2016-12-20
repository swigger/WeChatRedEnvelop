#import <Foundation/Foundation.h>
#import "WCRERootListController.h"
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

#if __has_feature(objc_arc)
		_specifiers = [self loadSpecifiersFromPlistName:@"Root" target:self];
#else
		_specifiers = [[self loadSpecifiersFromPlistName:@"Root" target:self] retain];
#endif
	}

	return _specifiers;
}

- (NSArray*) numValues{
	NSMutableArray * arr = [[NSMutableArray alloc] init];
	for (int i=1; i<=120; ++i)
	{
		if (i>10 && (i%5)!=0) continue;
		if (i>30 && (i%30)!=0) continue;
		[arr addObject:@(i)];
	}
	return arr;
}

- (NSArray*) numTitles{
	NSMutableArray * arr = [[NSMutableArray alloc] init];
	for (int i=1; i<=120; ++i)
	{
		if (i>10 && (i%5)!=0) continue;
		if (i>30 && (i%30)!=0) continue;
		[arr addObject:[NSString stringWithFormat:@"%ds", i]];
	}
	return arr;
}


@end




@interface KeywordsControler : UIViewController
@property (strong, nonatomic) UINavigationController * rootController;
@property (strong, nonatomic) PSListController * parentController;
@end

#define PL_PATH @"/var/mobile/Library/Preferences/net.swigger.wcreopt.plist"

@implementation KeywordsControler{
	CGRect _keybd;
	NSString * _id;
}

- (void) setSpecifier:(PSSpecifier *)spec{
	_id = spec.identifier;
}

- (NSString*) text{
	NSUserDefaults * def = [[NSUserDefaults alloc]initWithSuiteName:@"net.swigger.wcreopt"];
	NSString * s = (NSString*) [def objectForKey:_id];
	if (!s) s = @"";
	return s;
}

- (void) setText:(NSString*)text {
	NSUserDefaults * def = [[NSUserDefaults alloc]initWithSuiteName:@"net.swigger.wcreopt"];
	[def setObject:text forKey:_id];
}

- (void)loadView{
	CGRect applicationFrame = [[UIScreen mainScreen] bounds];
	applicationFrame.origin.y += _rootController.navigationBar.frame.size.height;
	applicationFrame.size.height -= _rootController.navigationBar.frame.size.height;

	UITextView *contentView = [[UITextView alloc] initWithFrame:applicationFrame];
	[contentView setFont:[UIFont systemFontOfSize:15]];
	contentView.scrollEnabled = YES;
	contentView.text = [self text];
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
		UITextView * tv = (UITextView*)self.view;
		[self setText:tv.text];
	}
}

@end
