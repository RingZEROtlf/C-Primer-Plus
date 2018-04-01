#include <stdio.h>
#include <stdbool.h>

typedef unsigned int uint32_t;

struct font_s
{
    uint32_t id:    8;  // 0~255
    uint32_t size:  7;  // 0~127
    uint32_t:       1;
    uint32_t align: 2;  // 0~2, 0 for left-alignment, 1 for middle-alignment, 2 for right-alignment
    uint32_t is_bold:   1;  // 0~1, 1 for on, 0 for off
    uint32_t is_italic: 1;  // 0~1, 1 for on, 0 for off
    uint32_t is_underlined: 1;  // 0~1, 1 for on, 0 for off
    uint32_t:       3;
};

union u
{
    struct font_s f;
    uint32_t b;
};

#define FONT_ID_MASK        ((uint32_t) 0xFF)
#define FONT_SIZE_MASK      ((uint32_t) 0x7F00)
#define FONT_BOLD_MASK      ((uint32_t) 0x40000)
#define FONT_ITALIC_MASK    ((uint32_t) 0x80000)
#define FONT_UNDERLINE_MASK ((uint32_t) 0x100000)

#define ALIGN_LEFT      0x0
#define ALIGN_CENTER    0x1
#define ALIGN_RIGHT     0x2
char *states_alignment[3] = { "left", "center", "right" };
char *states_on_or_off[2] = { "off", "on" };

char buffer[1024];

void output_font_settings(struct font_s *pfont);
char output_menu_and_get_choice();

int main()
{
    union u font = { { 1, 12, ALIGN_RIGHT, false, false, false } };
    while (true) {
        output_font_settings(&font.f);
        char choice = output_menu_and_get_choice();
        if (choice == 'q') break;
        uint32_t id, size;
        char alignment, set;
        switch (choice) {
        case 'f':
            printf("Enter font id (0-255): ");
            gets(buffer);
            sscanf(buffer, "%u", &id);
            font.b &= ~FONT_ID_MASK;
            font.b |= id;
            break;
        case 's':
            printf("Enter font size (0-127): ");
            gets(buffer);
            sscanf(buffer, "%u", &size);
            font.b &= ~FONT_SIZE_MASK;
            font.b |= size << 8;
            break;
        case 'a':
            while (true) {
                puts("Select alignment:");
                puts("l)left    c)center    r)right");
                alignment = getchar();
                if (alignment != '\n') gets(buffer);
                if (alignment == 'l' || alignment == 'c' || alignment == 'r') break; else puts("Invalid alignment!\n");
            }
            switch (alignment) {
            case 'l': font.f.align = ALIGN_LEFT; break;
            case 'c': font.f.align = ALIGN_CENTER; break;
            case 'r': font.f.align = ALIGN_RIGHT; break;
            default: break;
            }
            break;
        case 'b':
            font.b ^= FONT_BOLD_MASK;
            break;
        case 'i':
            font.b ^= FONT_ITALIC_MASK;
            break;
        case 'u':
            font.b ^= FONT_UNDERLINE_MASK;
            break;
        default:
            break;
        }
        putchar('\n');
    }
    puts("Bye!");
    return 0;
}

void output_font_settings(struct font_s *pfont)
{
    printf(" ID SIZE ALIGNMENT  B   I   U\n");
    printf("%3u %4u   %-6s  %-3s %-3s %-3s\n\n", 
           pfont->id, 
           pfont->size, 
           states_alignment[pfont->align], 
           states_on_or_off[pfont->is_bold],
           states_on_or_off[pfont->is_italic],
           states_on_or_off[pfont->is_underlined]);
}

char output_menu_and_get_choice()
{
    char choice;
    while (true) {
        puts("f)change font     s)change size       a)change alignment");
        puts("b)toggle bold     i)toggle italic     u)toggle underline");
        puts("q)quit");
        choice = getchar();
        if (choice != '\n') gets(buffer);
        if (choice == 'f' || choice == 's' || choice == 'a' || choice == 'b' || choice == 'i' || choice == 'u' || choice == 'q')
            return choice;
        else
            puts("Invalid choice!\n");
    }
}