#ifndef CELESTIAL_H
#define CELESTIAL_H

#include <CoreFoundation/CoreFoundation.h>
#include <CoreAudio/CoreAudio.h>

#import <Celestial/CDStructures.h>
#import <Celestial/AVController.h>

typedef void * FigAudioOutputUnitRef;
typedef void * FigNotificationCenterRef;
typedef void * FigNotificationCallback;

extern CFStringRef kFigMoviePlaybackNotification_UserVolumeDidChange;
extern CFStringRef kFigMoviePlaybackNotification_ServerConnectionDied;

/* duid can be null. */
int FigAudioOutputUnitOpen(CFTypeRef duid, FigAudioOutputUnitRef *outputUnit);
unsigned int FigAudioOutputUnitInitialize(FigAudioOutputUnitRef outputUnit);
void FigNotificationCenterGetDefaultLocalCenter();
unsigned int FigNotificationCenterAddListener(FigNotificationCenterRef
    notificationCenter, void *userInfo, FigNotificationCallback *callback,
    CFStringRef whichNotification);

#endif

