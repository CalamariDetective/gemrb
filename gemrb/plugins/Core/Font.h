#ifndef FONT_H
#define FONT_H

#include "../../includes/globals.h"
#include <vector>

typedef struct StringList {
	Sprite2D     *** strings;
	unsigned int   * heights;
	unsigned int   * lengths;
	int StringCount;
	int starty;
	int curx;
	int cury;
} StringList;

#ifdef WIN32

#ifdef GEM_BUILD_DLL
#define GEM_EXPORT __declspec(dllexport)
#else
#define GEM_EXPORT __declspec(dllimport)
#endif

#else
#define GEM_EXPORT
#endif

#define IE_FONT_ALIGN_LEFT   0x00
#define IE_FONT_ALIGN_CENTER 0x01
#define IE_FONT_ALIGN_RIGHT  0x02
#define IE_FONT_ALIGN_TOP    0x10 //Single-Line and Multi-Line Text
#define IE_FONT_ALIGN_MIDDLE 0x20 //Only for single line Text
#define IE_FONT_SINGLE_LINE  0x40

class GEM_EXPORT Font
{
private:
	//std::vector<Sprite2D*> chars;
	int count;
	Color * palette;
public:
	Font(void);
	~Font(void);
	void AddChar(Sprite2D * spr);
	void Print(Region rgn, unsigned char * string, Color *color, unsigned char Alignment, bool anchor = false, Font * initials = NULL, Color *initcolor = NULL, Sprite2D * cursor = NULL, int curpos = 0);
	void PrintFromLine(int startrow, Region rgn, unsigned char * string, Color *color, unsigned char Alignment, bool anchor = false, Font * initials = NULL, Color *initcolor = NULL, Sprite2D * cursor = NULL, int curpos = 0);
	void * GetPalette();
	char ResRef[9];
	Sprite2D * chars[256];
	int maxHeight;
private: // Private methods
  /** PreCalculate for Printing */
  StringList Prepare(Region &rgn, unsigned char * string, Font * init, int curpos);
  int CalcStringWidth(const char * string);
public:
  void SetupString(char * string, int width);
};

#endif
