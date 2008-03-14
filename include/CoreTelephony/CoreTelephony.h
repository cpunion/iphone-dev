#ifndef CORETELEPHONY_H_
#define CORETELEPHONY_H_

#include <CoreFoundation/CoreFoundation.h>

struct __CTServerConnection {
  int a;
  int b;
  CFMachPortRef myport;
  int c;
  int d;
  int e;
  int f;
  int g;
  int h;
  int i;
};
typedef struct __CTServerConnection CTServerConnection;
typedef CTServerConnection* CTServerConnectionRef;

struct __CellInfo {
  int servingmnc;
  int network;
  int location;
  int cellid;
  int station;
  int freq;
  int rxlevel;
  int c1;
  int c2;
};
typedef struct __CellInfo CellInfo;
typedef CellInfo* CellInfoRef;

CTServerConnectionRef _CTServerConnectionCreate(CFAllocatorRef allocator,
                                                void(*callback)(void),
                                                int *unknown);

mach_port_t _CTServerConnectionGetPort(CCTServerConnectionRef);

void _CTServerConnectionCellMonitorStart(mach_port_t*, CTServerConnectionRef);

// kCTCellMonitorUpdateNotification?
void _CTServerConnectionRegisterForNotification(void *,
                                                CTServerConnectionRef,
                                                void(*callback)(void));
void kCTCellMonitorUpdateNotification();

void _CTServerConnectionCellMonitorGetCellCount(mach_port_t* port,
                                                CTServerConnectionRef,
                                                int *cellinfo_count);

void _CTServerConnectionCellMonitorGetCellInfo(mach_port_t* port,
                                               CTServerConnectionRef,
                                               int cellinfo_number,
                                               CellInfoRef);

#endif  // CORETELEPHONY_H_
