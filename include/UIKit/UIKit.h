#ifndef UIKIT_H
#define UIKIT_H
#import <CoreGraphics/CoreGraphics.h>
#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>

/* Don't add files to this unless you've made sure they compile. --pcwalton */

#import <UIKit/CDStructures.h>
#import <UIKit/UIAlertSheet.h>
#import <UIKit/UIAlphaAnimation.h>
#import <UIKit/UIAnimation.h>
#import <UIKit/UIAnimator.h>
#import <UIKit/UIApplication.h>
#import <UIKit/UIBezierPath.h>
#import <UIKit/UIGradientBar.h>
#import <UIKit/UIHardware.h>
#import <UIKit/UIImage.h>
#import <UIKit/UIImageAndTextTableCell.h>
#import <UIKit/UIImageView.h>
#import <UIKit/UIKeyboard.h>
#import <UIKit/UIKeyboardImpl.h>
#import <UIKit/UIKeyboardInput.h>
#import <UIKit/UINavigationBar.h>
#import <UIKit/UINavigationItem.h>
#import <UIKit/UISearchField.h>
#import <UIKit/UITable.h>
#import <UIKit/UITableColumn.h>
#import <UIKit/UITextLabel.h>
#import <UIKit/UITextView.h>
#import <UIKit/UIThreePartButton.h>
#import <UIKit/UITransitionView.h>
#import <UIKit/UITransformAnimation.h>
#import <UIKit/UIView.h>
#import <UIKit/UIView-Animation.h>
#import <UIKit/UIView-Geometry.h>
#import <UIKit/UIView-Gestures.h>
#import <UIKit/UIView-Hierarchy.h>
#import <UIKit/UIView-Internal.h>
#import <UIKit/UIView-LKLayerDelegate.h>
#import <UIKit/UIView-Rendering.h>
#import <UIKit/UIWindow.h>
#import <UIKit/WebCaretChangeListenerProtocol.h>

#ifdef __cplusplus
extern "C" {
#endif

extern UIApplication *UIApp;

extern NSString *UITextFieldTextDidBeginEditingNotification;
extern NSString *UITextFieldTextDidEndEditingNotification;
extern NSString *UITextFieldTextDidChangeNotification;

/* Updated for FW v1.2 */

#define UIApplicationMain(A, B, C) { \
    UIApplicationMain(A, B, \
        [ NSString stringWithCString: (char *) class_getName(C) ], \
        [ NSString stringWithCString: (char *) class_getName(C) ])  \
  }


/* Updated for FW v1.2 */
CGContextRef UIGraphicsGetCurrentContext();
#define UICurrentContext UIGraphicsGetCurrentContext

struct CGAffineTransform UIIntegralTransform();

#ifdef __cplusplus
}
#endif

#endif

