// Copyright (c) 2016, Baidu.com, Inc. All Rights Reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

#include <stdio.h>
#include <unistd.h>

#include <rw_lock.h>
#include <thread.h>

baidu::common::RWLock rw_lock;

void UnlockFunc() {
    rw_lock.Unlock();
}

void ReadLockFunc() {
    rw_lock.ReadLock();
    sleep(10);
    UnlockFunc();
}

void WriteLockFunc() {
    rw_lock.WriteLock();
    UnlockFunc();
}

int main() {
    baidu::common::Thread t1, t2, t3, t4;
    t1.Start(ReadLockFunc);
    t2.Start(WriteLockFunc);
    t3.Start(ReadLockFunc);
    t4.Start(WriteLockFunc);
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
