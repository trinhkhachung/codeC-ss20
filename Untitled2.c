#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char id[10];
    char name[50];
    float importPrice;
    float salePrice;
    int quantity;
} Product;

Product products[MAX];
int productCount = 0;

void nhapSanPham() {
    if (productCount >= MAX) {
        printf("danh sach san pham da day.\n");
        return;
    }
    printf("nhap ma san pham: ");
    scanf("%s", products[productCount].id);
    printf("nhap ten san pham: ");
    scanf(" %[^\n]", products[productCount].name);
    printf("nhap gia nhap: ");
    scanf("%f", &products[productCount].importPrice);
    printf("nhap gia ban: ");
    scanf("%f", &products[productCount].salePrice);
    printf("nhap so luong: ");
    scanf("%d", &products[productCount].quantity);
    productCount++;
    printf("da nhap san pham thanh cong.\n");
}

void hienThiSanPham() {
    if (productCount == 0) {
        printf("khong co san pham trong danh sach.\n");
        return;
    }
    printf("\n%-10s %-30s %-10s %-10s %-10s\n", "ma", "ten", "gia nhap", "gia ban", "so luong");
    for (int i = 0; i < productCount; i++) {
        printf("%-10s %-30s %-10.2f %-10.2f %-10d\n",
               products[i].id, products[i].name, products[i].importPrice, products[i].salePrice, products[i].quantity);
    }
}

void capNhatSanPham() {
    char id[10];
    printf("nhap ma san pham de cap nhat: ");
    scanf("%s", id);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].id, id) == 0) {
            printf("nhap ten san pham moi: ");
            scanf(" %[^\n]", products[i].name);
            printf("nhap gia nhap moi: ");
            scanf("%f", &products[i].importPrice);
            printf("nhap gia ban moi: ");
            scanf("%f", &products[i].salePrice);
            printf("nhap so luong moi: ");
            scanf("%d", &products[i].quantity);
            printf("da cap nhat san pham thanh cong.\n");
            return;
        }
    }
    printf("khong tim thay san pham voi ma da nhap.\n");
}

void sapXepSanPhamTheoGia() {
    if (productCount == 0) {
        printf("khong co san pham trong danh sach de sap xep.\n");
        return;
    }
    for (int i = 0; i < productCount - 1; i++) {
        for (int j = i + 1; j < productCount; j++) {
            if (products[i].salePrice > products[j].salePrice) {
                Product temp = products[i];
                products[i] = products[j];
                products[j] = temp;
            }
        }
    }
    printf("da sap xep san pham theo gia ban thanh cong.\n");
}

void timKiemSanPham() {
    char name[50];
    printf("nhap ten san pham de tim: ");
    scanf(" %[^\n]", name);

    int found = 0;
    for (int i = 0; i < productCount; i++) {
        if (strstr(products[i].name, name)) {
            printf("%-10s %-30s %-10.2f %-10.2f %-10d\n",
                   products[i].id, products[i].name, products[i].importPrice, products[i].salePrice, products[i].quantity);
            found = 1;
        }
    }
    if (!found) {
        printf("khong tim thay san pham voi ten da nhap.\n");
    }
}

void banSanPham() {
    char id[10];
    int quantity;
    printf("nhap ma san pham can ban: ");
    scanf("%s", id);

    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].id, id) == 0) {
            printf("nhap so luong can ban: ");
            scanf("%d", &quantity);

            if (quantity > products[i].quantity) {
                printf("khong du so luong trong kho.\n");
            } else {
                products[i].quantity -= quantity;
                printf("da ban thanh cong %d san pham.\n", quantity);
            }
            return;
        }
    }
    printf("khong tim thay san pham voi ma da nhap.\n");
}

void doanhThuHienTai() {
    float total = 0;
    for (int i = 0; i < productCount; i++) {
        total += (products[i].salePrice - products[i].importPrice) * (products[i].quantity);
    }
    printf("doanh thu hien tai la: %.2f\n", total);
}

void menu() {
    int choice;
    do {
        printf("\n--- QUAN LY SAN PHAM ---\n");
        printf("1. nhap san pham\n");
        printf("2. hien thi san pham\n");
        printf("3. cap nhat san pham\n");
        printf("4. sap xep san pham theo gia\n");
        printf("5. tim kiem san pham\n");
        printf("6. ban san pham\n");
        printf("7. doanh thu hien tai\n");
        printf("8. thoat\n");
        printf("nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapSanPham();
                break;
            case 2:
                hienThiSanPham();
                break;
            case 3:
                capNhatSanPham();
                break;
            case 4:
                sapXepSanPhamTheoGia();
                break;
            case 5:
                timKiemSanPham();
                break;
            case 6:
                banSanPham();
                break;
            case 7:
                doanhThuHienTai();
                break;
            case 8:
                printf("thoat chuong trinh.\n");
                break;
            default:
                printf("lua chon khong hop le. vui long nhap lai.\n");
        }
    } while (choice != 8);
}

int main() {
    menu();
    return 0;
}

