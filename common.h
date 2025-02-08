#ifndef COMMON_H
    #define COMMON_H
#endif

//#define USE_32_BITS

#define SIDES 6
#define EMPTY_FACE -1
#define CENTER_SQUARE 9
#define CUBE_REPRESENTATION_LENGTH 48

#if defined(USE_32_BITS)
    #define SQUARE_SIZE 4
#else
    #define SQUARE_SIZE 8
#endif

#define FACE_SQUARE_COUNT 8

#define bool int
#define true 1
#define false 0

#if defined(USE_32_BITS)
    #define u_int unsigned int
#else
    #define u_int unsigned long
#endif

#define byte unsigned char

#if defined(USE_32_BITS)
    #define SQUARE_FIRST_BYTE ((u_int)0x0000000f)
#else
    #define SQUARE_FIRST_BYTE ((u_int)0x00000000000000ff)
#endif

#define SQUARE_COLOR(face, square) (((face) >> (SQUARE_SIZE * (FACE_SQUARE_COUNT - square))) & SQUARE_FIRST_BYTE)
#define SET_SQUARE_COLOR(face, square, color) ((face) |= ((color) << (SQUARE_SIZE * (FACE_SQUARE_COUNT - (square)))))
#define UPDATE_SQUARE_COLOR(face, square, color) (face = ((face & FACE_SQUARE_MASKS [square]) | (color << (SQUARE_SIZE * (FACE_SQUARE_COUNT - square)))))
#define ROTATE_RIGHT(face) ((face >> (SQUARE_SIZE * 2)) | (face << (SQUARE_SIZE * 6)))
#define ROTATE_LEFT(face) ((face << (SQUARE_SIZE * 2)) | (face >> (SQUARE_SIZE * 6)))

extern bool debug_enabled;
extern bool use_terminal_colors;

extern const u_int DOWN;
extern const u_int RIGHT;
extern const u_int FRONT;
extern const u_int LEFT;
extern const u_int BACK;
extern const u_int UP;

extern const char DOWN_CHAR;
extern const char RIGHT_CHAR;
extern const char FRONT_CHAR;
extern const char LEFT_CHAR;
extern const char BACK_CHAR;
extern const char UP_CHAR;
extern const char DOWN_PRIME_CHAR;
extern const char RIGHT_PRIME_CHAR;
extern const char FRONT_PRIME_CHAR;
extern const char LEFT_PRIME_CHAR;
extern const char BACK_PRIME_CHAR;
extern const char UP_PRIME_CHAR;

extern const u_int WHITE;
extern const u_int GREEN;
extern const u_int RED;
extern const u_int BLUE;
extern const u_int ORANGE;
extern const u_int YELLOW;

extern const char WHITE_CHAR;
extern const char GREEN_CHAR;
extern const char RED_CHAR;
extern const char BLUE_CHAR;
extern const char ORANGE_CHAR;
extern const char YELLOW_CHAR;
extern const char EMPTY_SQUARE_CHAR;

extern const char SOLVED_POSITION[];
extern const char LEGAL_MOVES[];
extern const char LEGAL_COLORS[];

u_int COLOR_VALUES [100];
char COLOR_CHARS[SIDES];
char FACE_CHARS[SIDES];
char * COLOR_NAMES[SIDES];
char * COLOR_CODES[SIDES];
char * RESET_COLOR_CODE;

extern const u_int ADJACENT_SIDES[SIDES][4];
extern const int ADJACENT_SQUARES[SIDES][4][3];
u_int FACE_SQUARE_MASKS[FACE_SQUARE_COUNT+1];

u_int MOVE_FACES[SIDES*2];

// Edge/Cross constants

#define EDGE_COUNT 12
#define EDGE_ORIENTATIONS 2

extern u_int EDGE_LOOKUP_TABLE[ EDGE_COUNT * EDGE_ORIENTATIONS ][4];

void EnableDebug(bool);
int Strlen(char *);
bool StrCmp(char *, char *);
bool IsLower(char *);
void Init();
bool IsLegalChar(char);
bool IsLegalMove(char);
bool IsValidCubeString(char *);
bool IsValidMoveString(char *);

const u_int ORDER [SIDES];

typedef struct {
    u_int * Faces; 
} Cube;

void ParseCube(char *, Cube *);
char * GetCubeString(Cube *);

u_int RepresentationPattern[3][4];
int SquareRepresentationPattern[3][3];

void PrintCubeRepresentation(Cube *);
void PrintInvalidRepresentationMessage();
void PrintInvalidMovesMessage();

char * GenerateRandomScramble(int);
void ApplyAlgorithm(Cube *, char *);
void Move(Cube *, char);
void Rotate(Cube *, u_int, bool);

void DisposeCube(Cube *);

void OutputHelpText();