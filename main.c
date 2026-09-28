#include <stdio.h>
#include <string.h>

int main() {
    // Yêu cầu 4: Khai báo mảng và biến toàn bộ trong main, không dùng struct
    const int MAX_PHIEU = 50;
    char maPhieu[50][20] = {"PM101", "PM102", "PM103"};
    int ngayQuaHan[50] = {0, 3, 5};
    int soLuong = 3;
    int luaChon;

    do {
        // Hiển thị menu
        printf("\n--- HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ---\n");
        printf("1. Xem danh sach phieu muon\n");
        printf("2. Them moi phieu muon\n");
        printf("3. Cap nhat so ngay qua han\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &luaChon);

        // Yêu cầu 2: Làm sạch bộ đệm bàn phím sau khi nhập số
        while (getchar() != '\n');

        switch (luaChon) {
            case 1: {
                printf("\n--- DANH SACH PHIEU MUON SACH ---\n");
                printf("STT | Ma Phieu | So Ngay Qua Han | Tien Phat (VND)\n");
                printf("--------------------------------------------------\n");
                for (int i = 0; i < soLuong; i++) {
                    // Yêu cầu 1: Tính tiền phạt
                    long long tienPhat = (long long)ngayQuaHan[i] * 5000;
                    printf("%d | %s | %d ngay | %lld VND\n", i + 1, maPhieu[i], ngayQuaHan[i], tienPhat);
                }
                printf("--------------------------------------------------\n");
                printf("Tong so phieu: %d\n", soLuong);
                break;
            }
            case 2: {
                // Yêu cầu 3: Kiểm tra giới hạn số lượng phiếu
                if (soLuong >= MAX_PHIEU) {
                    printf("Loi: Danh sach phieu muon da day, khong the them!\n");
                } else {
                    printf("Nhap ma phieu muon moi: ");
                    scanf("%s", maPhieu[soLuong]);
                    while (getchar() != '\n'); // Làm sạch bộ đệm sau khi nhập chuỗi

                    // Mặc định số ngày quá hạn ban đầu = 0
                    ngayQuaHan[soLuong] = 0;
                    soLuong++;
                    printf("Them thanh cong! Tong so phieu hien tai la %d.\n", soLuong);
                }
                break;
            }
            case 3: {
                char maCanTim[20];
                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%s", maCanTim);
                while (getchar() != '\n'); // Làm sạch bộ đệm

                int viTri = -1;
                // Tìm kiếm mã phiếu trong mảng
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maCanTim) == 0) {
                        viTri = i;
                        break;
                    }
                }

                if (viTri != -1) {
                    printf("Tim thay phieu muon '%s' tai vi tri index %d.\n", maCanTim, viTri);
                    int soNgayMoi;

                    // Yêu cầu 3: Kiểm tra số ngày quá hạn >= 0
                    do {
                        printf("Nhap so ngay qua han moi: ");
                        scanf("%d", &soNgayMoi);
                        while (getchar() != '\n'); // Làm sạch bộ đệm

                        if (soNgayMoi < 0) {
                            printf("Loi: So ngay qua han phai la so nguyen khong am. Vui long nhap lai!\n");
                        }
                    } while (soNgayMoi < 0);

                    // Cập nhật giá trị mới
                    ngayQuaHan[viTri] = soNgayMoi;
                    printf("Cap nhat thanh cong! So ngay qua han moi cua %s la %d ngay.\n", maCanTim, soNgayMoi);
                } else {
                    printf("Khong tim thay phieu muon mang ma '%s'.\n", maCanTim);
                }
                break;
            }
            case 0:
                printf("Da thoat chuong trinh. Chao tam biet!\n");
                break;
            default:
                printf("Loi: Chuc nang khong ton tai. Vui long chon lai (0-3).\n");
                break;
        }
    } while (luaChon != 0);

    return 0;
}