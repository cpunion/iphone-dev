#ifndef MOBILE_MUSIC_PLAYER_H
#define MOBILE_MUSIC_PLAYER_H

#import <CoreFoundation/CoreFoundation.h>

// Returns 1 if MobileMusicPlayer is running, 0 otherwise.
int PCIsPlayerRunning();

// Returns the number of songs in the currently playlist
int PCGetCount();

int PCPlayerGetSongCount();
int PCGetPlaylistCount();

// Returns the index of the current song within the current playlist, or -1
int PCPlayerGetCurrentPlayingSong();

// Returns time in ms, or 0
int PCGetCurrentPlayingSongTime();
// Returns time in ms, or -1000
int PCGetCurrentPlayingSongDuration();

// Jumps to the current time in ms
void PCPlayerSeekToTime(int time);

typedef enum {
  kPlayerStopped = 0,
  kPlayerPlaying = 1,
  kPlayerPaused = 2,
} PlayerState;

PlayerState PCGetPlaybackState();
void PCSetPlaybackState(void* unknown, PlayerState state);

// Methods for creating and destroying an IAP Connect
int PCCreateIAPConnection();
void PCCloseConnection(int connection);

int PCPlayerGetIdentifierAtIndex(void* unknown, int index);

typedef enum {
  kPropertyGenre = 0x0,
  kPropertyArtist = 0x1,
  // Always seems to be empty.
  // kPropertyUnknown = 0x2,
  kPropertyAlbumTitle = 0x3,
  kPropertySongTitle = 0x4,
  // 0x6 always seems to be the same as 0x3
  // kPropertyAlbumTitle2 = 0x6
  kPlayerPropertyFilename = 0xc
} PlayerProperty;

char* PCCopyStringValueForPropertyForIdentifier(int iap_conn, PlayerProperty b,
                                                int identifier);

#endif  /* MOBILE_MUSIC_PLAYER_H */
