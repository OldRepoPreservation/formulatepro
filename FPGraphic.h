//
//  FPGraphic.h
//  FormulatePro
//
//  Created by Andrew de los Reyes on 7/5/06.
//  Copyright 2006 Andrew de los Reyes. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class MyPDFView;
@class PDFPage;

enum {
    NoKnob = 0,
    UpperLeftKnob   = 1 << 0,
    UpperMiddleKnob = 1 << 1,
    UpperRightKnob  = 1 << 2,
    MiddleLeftKnob  = 1 << 3,
    MiddleRightKnob = 1 << 4,
    LowerLeftKnob   = 1 << 5,
    LowerMiddleKnob = 1 << 6,
    LowerRightKnob  = 1 << 7,
};

@interface FPGraphic : NSObject {
    NSRect _bounds;
    NSRect _naturalBounds;
    NSRect _origBounds; // for bulk move operations
    struct __gFlags {
        unsigned int drawsFill:1;
        unsigned int drawsStroke:1;
        unsigned int manipulatingBounds:1;
        unsigned int _pad:29;
    } _gFlags;
    float _lineWidth;
    NSColor *_fillColor;
    NSColor *_strokeColor;
    int _knobMask;
    
    MyPDFView *_pdfView;
    PDFPage *_page;
}

+ (FPGraphic *)graphicInPDFView:(MyPDFView *)pdfView;
- (FPGraphic *)initInPDFView:(MyPDFView *)pdfView;

- (BOOL)placeWithEvent:(NSEvent *)theEvent;
- (void)resizeWithEvent:(NSEvent *)theEvent byKnob:(int)knob;
- (void)moveGraphicByX:(float)x byY:(float)y;

- (PDFPage *)page;

- (void)draw;
- (void)drawKnobs;
- (int)knobForEvent:(NSEvent *)theEvent;
- (NSRect)pageRectForKnob:(int)knob isBoundRect:(BOOL)isBound;

- (NSRect)bounds;
- (NSRect)safeBounds;
- (NSRect)boundsWithKnobs;
- (float)lineWidth;


@end
