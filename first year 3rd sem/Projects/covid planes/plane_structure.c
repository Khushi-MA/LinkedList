struct plane_info
{
    int id;
    char dest[30];
    int seats;
    struct plane_info* next;
};

typedef struct plane_info* NODE;
