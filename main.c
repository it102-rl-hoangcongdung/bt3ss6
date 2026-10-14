#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char maPhieu[MAX][20];
    char maSach[MAX][20];
    int soNgayMuon[MAX];
    int soLuong = 0;
    int choice;

    do {
        printf("\n================ HỆ THỐNG QUẢN LÝ MƯỢN TRẢ SÁCH (LOGISTICS) ================\n");
        printf("1. Thêm mới phiếu mượn sách (Create)\n");
        printf("2. Hiển thị danh sách phiếu mượn & Tiền phạt quá hạn (Read)\n");
        printf("3. Cập nhật số ngày mượn sách (Update)\n");
        printf("4. Xác nhận trả sách / Xóa phiếu mượn (Delete)\n");
        printf("5. Thoát chương trình\n");
        printf("===========================================================================\n");
        printf("Lựa chọn của bạn (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Lựa chọn không hợp lệ, vui lòng chọn lại!\n");
            while(getchar() != '\n');
            continue;
        }
        while(getchar() != '\n');

        switch(choice) {
            case 1: {
                if (soLuong >= MAX) {
                    printf("Bộ nhớ danh sách đã đầy, không thể thêm mới!\n");
                    break;
                }
                char tempMaPhieu[20];
                printf("--- THÊM MỚI PHIẾU MƯỢN ---\n");
                printf("Nhập mã phiếu: ");
                scanf("%19s", tempMaPhieu);
                while(getchar() != '\n');

                int trung = 0;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], tempMaPhieu) == 0) {
                        trung = 1;
                        break;
                    }
                }

                if (trung) {
                    printf("Mã phiếu đã tồn tại trong hệ thống!\n");
                    break;
                }

                strcpy(maPhieu[soLuong], tempMaPhieu);
                printf("Nhập mã sách: ");
                scanf("%19s", maSach[soLuong]);
                while(getchar() != '\n');

                printf("Nhập số ngày mượn: ");
                scanf("%d", &soNgayMuon[soLuong]);
                while(getchar() != '\n');

                soLuong++;
                printf("Thêm mới phiếu mượn thành công!\n");
                break;
            }
            case 2: {
                if (soLuong == 0) {
                    printf("Danh sách phiếu mượn hiện đang rỗng!\n");
                    break;
                }
                printf("================================ DANH SÁCH PHIẾU MƯỢN ================================\n");
                printf("%-4s %-12s %-12s %-10s %-12s %-15s\n", "STT", "MÃ PHIẾU", "MÃ SÁCH", "SỐ NGÀY", "TRẠNG THÁI", "TIỀN PHẠT (VNĐ)");
                for (int i = 0; i < soLuong; i++) {
                    int ngayQuaHan = 0;
                    long tienPhat = 0;
                    char* trangThai = "ĐÚNG HẠN";
                    if (soNgayMuon[i] > 14) {
                        ngayQuaHan = soNgayMuon[i] - 14;
                        tienPhat = (long)ngayQuaHan * 5000;
                        trangThai = "QUÁ HẠN";
                    }
                    printf("%-4d %-12s %-12s %-10d %-12s %-15ld\n", i + 1, maPhieu[i], maSach[i], soNgayMuon[i], trangThai, tienPhat);
                }
                printf("======================================================================================\n");
                break;
            }
            case 3: {
                char tempMaPhieu[20];
                printf("Nhập mã phiếu cần cập nhật: ");
                scanf("%19s", tempMaPhieu);
                while(getchar() != '\n');

                int pos = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], tempMaPhieu) == 0) {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1) {
                    printf("Không tìm thấy mã phiếu trong hệ thống!\n");
                } else {
                    printf("Số ngày mượn hiện tại của phiếu %s là: %d\n", maPhieu[pos], soNgayMuon[pos]);
                    printf("Nhập số ngày mượn mới: ");
                    scanf("%d", &soNgayMuon[pos]);
                    while(getchar() != '\n');
                    printf("Cập nhật số ngày mượn thành công!\n");
                }
                break;
            }
            case 4: {
                char tempMaPhieu[20];
                printf("Nhập mã phiếu xác nhận trả/xóa: ");
                scanf("%19s", tempMaPhieu);
                while(getchar() != '\n');

                int pos = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], tempMaPhieu) == 0) {
                        pos = i;
                        break;
                    }
                }

                if (pos == -1) {
                    printf("Không tìm thấy mã phiếu cần xóa!\n");
                } else {
                    for (int i = pos; i < soLuong - 1; i++) {
                        strcpy(maPhieu[i], maPhieu[i + 1]);
                        strcpy(maSach[i], maSach[i + 1]);
                        soNgayMuon[i] = soNgayMuon[i + 1];
                    }
                    soLuong--;
                    printf("Xác nhận trả sách và xóa phiếu mượn thành công!\n");
                }
                break;
            }
            case 5:
                printf("Cảm ơn bạn đã sử dụng hệ thống LIBRARY_WMS Logistics. Tạm biệt!\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ, vui lòng chọn lại!\n");
        }
    } while (choice != 5);

    return 0;
}