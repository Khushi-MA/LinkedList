
struct letter_info
{
    char name[30];                  // name of the person
    int hno;                        // house number
    char area[30];                  // area they live in
    double mobile;                  // phone number
    struct letter_info *next;       // pointer to point next
};


typedef struct letter_info* NODE;
