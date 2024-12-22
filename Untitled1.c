#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char id[10];
    char title[50];
    char author[50];
    float price;
    char category[30];
} Book;

Book books[MAX];
int bookCount = 0;

void themSach() {
    if (bookCount >= MAX) {
        printf("danh sach sach da day.\n");
        return;
    }
    printf("nhap ma sach: ");
    scanf("%s", books[bookCount].id);
    printf("nhap ten sach: ");
    scanf(" %[^"]", books[bookCount].title);
    printf("nhap tac gia: ");
    scanf(" %[^"]", books[bookCount].author);
    printf("nhap gia sach: ");
    scanf("%f", &books[bookCount].price);
    printf("nhap the loai: ");
    scanf(" %[^"]", books[bookCount].category);
    bookCount++;
    printf("da them sach thanh cong.\n");
}

void hienThiSach() {
    if (bookCount == 0) {
        printf("khong co sach trong danh sach.\n");
        return;
    }
    printf("\n%-10s %-30s %-20s %-10s %-20s\n", "ma", "ten", "tac gia", "gia", "the loai");
    for (int i = 0; i < bookCount; i++) {
        printf("%-10s %-30s %-20s %-10.2f %-20s\n", books[i].id, books[i].title, books[i].author, books[i].price, books[i].category);
    }
}

void themSachViTri() {
    if (bookCount >= MAX) {
        printf("danh sach sach da day.\n");
        return;
    }
    int position;
    printf("nhap vi tri de them sach (0 den %d): ", bookCount);
    scanf("%d", &position);
    if (position < 0 || position > bookCount) {
        printf("vi tri khong hop le.\n");
        return;
    }
    for (int i = bookCount; i > position; i--) {
        books[i] = books[i - 1];
    }
    printf("nhap ma sach: ");
    scanf("%s", books[position].id);
    printf("nhap ten sach: ");
    scanf(" %[^"]", books[position].title);
    printf("nhap tac gia: ");
    scanf(" %[^"]", books[position].author);
    printf("nhap gia sach: ");
    scanf("%f", &books[position].price);
    printf("nhap the loai: ");
    scanf(" %[^"]", books[position].category);
    bookCount++;
    printf("da them sach vao vi tri %d.\n", position);
}

void xoaSachTheoMa() {
    if (bookCount == 0) {
        printf("khong co sach trong danh sach de xoa.\n");
        return;
    }
    char id[10];
    printf("nhap ma sach de xoa: ");
    scanf("%s", id);

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].id, id) == 0) {
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
            bookCount--;
            printf("da xoa sach thanh cong.\n");
            return;
        }
    }
    printf("khong tim thay sach voi ma da nhap.\n");
}

void sapXepSachTheoGia() {
    if (bookCount == 0) {
        printf("khong co sach trong danh sach de sap xep.\n");
        return;
    }
    for (int i = 0; i < bookCount - 1; i++) {
        for (int j = i + 1; j < bookCount; j++) {
            if (books[i].price > books[j].price) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    printf("da sap xep sach theo gia thanh cong.\n");
}

void timSachTheoTen() {
    if (bookCount == 0) {
        printf("khong co sach trong danh sach de tim.\n");
        return;
    }
    char title[50];
    printf("nhap ten sach de tim: ");
    scanf(" %[^"]", title);

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strstr(books[i].title, title)) {
            printf("%-10s %-30s %-20s %-10.2f %-20s\n", books[i].id, books[i].title, books[i].author, books[i].price, books[i].category);
            found = 1;
        }
    }
    if (!found) {
        printf("khong tim thay sach voi ten da nhap.\n");
    }
}

void menu() {
    int choice;
    do {
        printf("\n--- QUAN LY SACH ---\n");
        printf("1. them sach\n");
        printf("2. hien thi sach\n");
        printf("3. them sach vao vi tri\n");
        printf("4. xoa sach theo ma\n");
        printf("5. sap xep sach theo gia\n");
        printf("6. tim sach theo ten\n");
        printf("7. thoat\n");
        printf("nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                themSach();
                break;
            case 2:
                hienThiSach();
                break;
            case 3:
                themSachViTri();
                break;
            case 4:
                xoaSachTheoMa();
                break;
            case 5:
                sapXepSachTheoGia();
                break;
            case 6:
                timSachTheoTen();
                break;
            case 7:
                printf("thoat chuong trinh.\n");
                break;
            default:
                printf("lua chon khong hop le. vui long nhap lai.\n");
        }
    } while (choice != 7);
}

int main() {
    menu();
    return 0;
}

