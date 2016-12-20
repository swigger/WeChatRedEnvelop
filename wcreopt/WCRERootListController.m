#import <Foundation/Foundation.h>
#import "WCRERootListController.h"
#import "Preferences/PSSpecifier.h"


@implementation WCRERootListController

- (NSArray *)specifiers {
	if (!_specifiers) {
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

#define PL_PATH @"/var/mobile/Library/Preferences/com.tencent.wcreopt.plist"

@implementation KeywordsControler{
	NSString * _id;
	BOOL kbdon;
}

- (void) setSpecifier:(PSSpecifier *)spec{
	_id = spec.identifier;
	kbdon = false;
}

- (NSString*) text{
	NSUserDefaults * def = [[NSUserDefaults alloc]initWithSuiteName:@"com.tencent.wcreopt"];
	NSString * s = (NSString*) [def objectForKey:_id];
	if (!s) s = @"";
	return s;
}

- (void) setText:(NSString*)text {
	NSUserDefaults * def = [[NSUserDefaults alloc]initWithSuiteName:@"com.tencent.wcreopt"];
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
	if (kbdon) return ;
	kbdon = true;

	NSDictionary *info  = notification.userInfo;
	NSValue      *value = info[UIKeyboardFrameEndUserInfoKey];

	CGRect rawFrame      = [value CGRectValue];
	CGRect keyboardFrame = [self.view convertRect:rawFrame fromView:nil];

	CGRect applicationFrame = [[UIScreen mainScreen] bounds];
	applicationFrame.origin.y += _rootController.navigationBar.frame.size.height;
	applicationFrame.size.height -= _rootController.navigationBar.frame.size.height;

	NSLog(@"keyboardFrame: %@", NSStringFromCGRect(keyboardFrame));

	CGRect frm = self.view.frame;
	frm.size.height = applicationFrame.size.height -  keyboardFrame.size.height;
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
