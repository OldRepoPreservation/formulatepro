/*
 *  FPLogging.h
 *  FormulatePro
 *
 *  Created by Andrew de los Reyes on 9/3/07.
 *  Copyright 2007 Andrew de los Reyes. All rights reserved.
 *
 */

// from http://www.cocoabuilder.com/archive/message/cocoa/2002/2/7/50783
#if DEBUG
inline void DLog(NSString *format, ...)
{
    va_list args;
    
    va_start(args, format);
    NSLogv(format, args);
    va_end(args);
}
#else
inline void DLog(NSString *format, ...) { }
#endif
