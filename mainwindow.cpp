#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>

#define MOV 0
#define ADD 1
#define SUB 2

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::string addBinary(std::string a, std::string b){
    std::string result = ""; // Initialize result
    int s = 0;          // Initialize digit sum

    // Traverse both strings starting from last
    // characters
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || s == 1)
    {
        // Comput sum of last digits and carry
        s += ((i >= 0)? a[i] - '0': 0);
        s += ((j >= 0)? b[j] - '0': 0);

        // If current digit sum is 1 or 3, add 1 to result
        result = char(s % 2 + '0') + result;

        // Compute carry
        s /= 2;

        // Move to next digits
        i--; j--;
    }
    return result;
}

int binary_to_int(std::string input){
    char* start = &input[0];
    int total = 0;
    while (*start)
    {
     total *= 2;
     if (*start++ == '1') total += 1;
    }
    return total;
}

std::string decimal_to_binary(int n){
    // array to store binary number
        int binaryNum[32];

        // counter for binary array
        int i = 0;
        while (n > 0) {

            // storing remainder in binary array
            binaryNum[i] = n % 2;
            n = n / 2;
            i++;
        }

        int binary=0;
        // printing binary array in reverse order
        for (int j = i - 1; j >= 0; j--)
            //std::cout << binaryNum[j];

        for (int j = i - 1; j >= 0; j--)
            binary += binaryNum[j]*pow(10, j);

        char* result;
        itoa(binary, result, 10);

        return result;
}

// =============================================    RADIOBUTTONS CLICKED
// ------------------------------------------------------------------ A 1
void MainWindow::on_radioButton_a1_15_clicked(){
    register_input_ah[0] = '1';
    ui->a_input_register_h->setText(QString::fromStdString(register_input_ah));
}
void MainWindow::on_radioButton_a1_14_clicked(){
    register_input_ah[1] = '1';
    ui->a_input_register_h->setText(QString::fromStdString(register_input_ah));
}
void MainWindow::on_radioButton_a1_13_clicked(){
    register_input_ah[2] = '1';
    ui->a_input_register_h->setText(QString::fromStdString(register_input_ah));
}
void MainWindow::on_radioButton_a1_12_clicked(){
    register_input_ah[3] = '1';
    ui->a_input_register_h->setText(QString::fromStdString(register_input_ah));
}
void MainWindow::on_radioButton_a1_11_clicked(){
    register_input_ah[4] = '1';
    ui->a_input_register_h->setText(QString::fromStdString(register_input_ah));
}
void MainWindow::on_radioButton_a1_10_clicked(){
    register_input_ah[5] = '1';
    ui->a_input_register_h->setText(QString::fromStdString(register_input_ah));
}
void MainWindow::on_radioButton_a1_9_clicked(){
    register_input_ah[6] = '1';
    ui->a_input_register_h->setText(QString::fromStdString(register_input_ah));
}
void MainWindow::on_radioButton_a1_8_clicked(){
    register_input_ah[7] = '1';
    ui->a_input_register_h->setText(QString::fromStdString(register_input_ah));
}
void MainWindow::on_radioButton_a1_7_clicked(){
    register_input_al[0] = '1';
    ui->a_input_register_l->setText(QString::fromStdString(register_input_al));
}
void MainWindow::on_radioButton_a1_6_clicked(){
    register_input_al[1] = '1';
    ui->a_input_register_l->setText(QString::fromStdString(register_input_al));
}
void MainWindow::on_radioButton_a1_5_clicked(){
    register_input_al[2] = '1';
    ui->a_input_register_l->setText(QString::fromStdString(register_input_al));
}
void MainWindow::on_radioButton_a1_4_clicked(){
    register_input_al[3] = '1';
    ui->a_input_register_l->setText(QString::fromStdString(register_input_al));
}
void MainWindow::on_radioButton_a1_3_clicked(){
    register_input_al[4] = '1';
    ui->a_input_register_l->setText(QString::fromStdString(register_input_al));
}
void MainWindow::on_radioButton_a1_2_clicked(){
    register_input_al[5] = '1';
    ui->a_input_register_l->setText(QString::fromStdString(register_input_al));
}
void MainWindow::on_radioButton_a1_1_clicked(){
    register_input_al[6] = '1';
    ui->a_input_register_l->setText(QString::fromStdString(register_input_al));
}
void MainWindow::on_radioButton_a1_0_clicked(){
    register_input_al[7] = '1';
    ui->a_input_register_l->setText(QString::fromStdString(register_input_al));
}
// ------------------------------------------------------------------ A 0
void MainWindow::on_radioButton_a0_0_clicked(){
    register_input_al[7] = '0';
    ui->a_input_register_l->setText(QString::fromStdString(register_input_al));
}
void MainWindow::on_radioButton_a0_1_clicked(){
    register_input_al[6] = '0';
    ui->a_input_register_l->setText(QString::fromStdString(register_input_al));
}
void MainWindow::on_radioButton_a0_2_clicked(){
    register_input_al[5] = '0';
    ui->a_input_register_l->setText(QString::fromStdString(register_input_al));
}
void MainWindow::on_radioButton_a0_3_clicked(){
    register_input_al[4] = '0';
    ui->a_input_register_l->setText(QString::fromStdString(register_input_al));
}
void MainWindow::on_radioButton_a0_4_clicked(){
    register_input_al[3] = '0';
    ui->a_input_register_l->setText(QString::fromStdString(register_input_al));
}
void MainWindow::on_radioButton_a0_5_clicked(){
    register_input_al[2] = '0';
    ui->a_input_register_l->setText(QString::fromStdString(register_input_al));
}
void MainWindow::on_radioButton_a0_6_clicked(){
    register_input_al[1] = '0';
    ui->a_input_register_l->setText(QString::fromStdString(register_input_al));
}
void MainWindow::on_radioButton_a0_7_clicked(){
    register_input_al[0] = '0';
    ui->a_input_register_l->setText(QString::fromStdString(register_input_al));
}
void MainWindow::on_radioButton_a0_8_clicked(){
    register_input_ah[7] = '0';
    ui->a_input_register_h->setText(QString::fromStdString(register_input_ah));
}
void MainWindow::on_radioButton_a0_9_clicked(){
    register_input_ah[6] = '0';
    ui->a_input_register_h->setText(QString::fromStdString(register_input_ah));
}
void MainWindow::on_radioButton_a0_10_clicked(){
    register_input_ah[5] = '0';
    ui->a_input_register_h->setText(QString::fromStdString(register_input_ah));
}
void MainWindow::on_radioButton_a0_11_clicked(){
    register_input_ah[4] = '0';
    ui->a_input_register_h->setText(QString::fromStdString(register_input_ah));
}
void MainWindow::on_radioButton_a0_12_clicked(){
    register_input_ah[3] = '0';
    ui->a_input_register_h->setText(QString::fromStdString(register_input_ah));
}
void MainWindow::on_radioButton_a0_13_clicked(){
    register_input_ah[2] = '0';
    ui->a_input_register_h->setText(QString::fromStdString(register_input_ah));
}
void MainWindow::on_radioButton_a0_14_clicked(){
    register_input_ah[1] = '0';
    ui->a_input_register_h->setText(QString::fromStdString(register_input_ah));
}
void MainWindow::on_radioButton_a0_15_clicked(){
    register_input_ah[0] = '0';
    ui->a_input_register_h->setText(QString::fromStdString(register_input_ah));
}
// ---------------------------------------------------------------- B 1
void MainWindow::on_radioButton_b1_0_clicked(){
    register_input_bl[7] = '1';
    ui->b_input_register_l->setText(QString::fromStdString(register_input_bl));
}
void MainWindow::on_radioButton_b1_1_clicked(){
    register_input_bl[6] = '1';
    ui->b_input_register_l->setText(QString::fromStdString(register_input_bl));
}
void MainWindow::on_radioButton_b1_2_clicked(){
    register_input_bl[5] = '1';
    ui->b_input_register_l->setText(QString::fromStdString(register_input_bl));
}
void MainWindow::on_radioButton_b1_3_clicked(){
    register_input_bl[4] = '1';
    ui->b_input_register_l->setText(QString::fromStdString(register_input_bl));
}
void MainWindow::on_radioButton_b1_4_clicked(){
    register_input_bl[3] = '1';
    ui->b_input_register_l->setText(QString::fromStdString(register_input_bl));
}
void MainWindow::on_radioButton_b1_5_clicked(){
    register_input_bl[2] = '1';
    ui->b_input_register_l->setText(QString::fromStdString(register_input_bl));
}
void MainWindow::on_radioButton_b1_6_clicked(){
    register_input_bl[1] = '1';
    ui->b_input_register_l->setText(QString::fromStdString(register_input_bl));
}
void MainWindow::on_radioButton_b1_7_clicked(){
    register_input_bl[0] = '1';
    ui->b_input_register_l->setText(QString::fromStdString(register_input_bl));
}
void MainWindow::on_radioButton_b1_8_clicked(){
    register_input_bh[7] = '1';
    ui->b_input_register_h->setText(QString::fromStdString(register_input_bh));
}
void MainWindow::on_radioButton_b1_9_clicked(){
    register_input_bh[6] = '1';
    ui->b_input_register_h->setText(QString::fromStdString(register_input_bh));
}
void MainWindow::on_radioButton_b1_10_clicked(){
    register_input_bh[5] = '1';
    ui->b_input_register_h->setText(QString::fromStdString(register_input_bh));
}
void MainWindow::on_radioButton_b1_11_clicked(){
    register_input_bh[4] = '1';
    ui->b_input_register_h->setText(QString::fromStdString(register_input_bh));
}
void MainWindow::on_radioButton_b1_12_clicked(){
    register_input_bh[3] = '1';
    ui->b_input_register_h->setText(QString::fromStdString(register_input_bh));
}
void MainWindow::on_radioButton_b1_13_clicked(){
    register_input_bh[2] = '1';
    ui->b_input_register_h->setText(QString::fromStdString(register_input_bh));
}
void MainWindow::on_radioButton_b1_14_clicked(){
    register_input_bh[1] = '1';
    ui->b_input_register_h->setText(QString::fromStdString(register_input_bh));
}
void MainWindow::on_radioButton_b1_15_clicked(){
    register_input_bh[0] = '1';
    ui->b_input_register_h->setText(QString::fromStdString(register_input_bh));
}
// ---------------------------------------------------------------- B 0

void MainWindow::on_radioButton_b0_0_clicked(){
    register_input_bl[7] = '0';
    ui->b_input_register_l->setText(QString::fromStdString(register_input_bl));
}
void MainWindow::on_radioButton_b0_1_clicked(){
    register_input_bl[6] = '0';
    ui->b_input_register_l->setText(QString::fromStdString(register_input_bl));
}
void MainWindow::on_radioButton_b0_2_clicked(){
    register_input_bl[5] = '0';
    ui->b_input_register_l->setText(QString::fromStdString(register_input_bl));
}
void MainWindow::on_radioButton_b0_3_clicked(){
    register_input_bl[4] = '0';
    ui->b_input_register_l->setText(QString::fromStdString(register_input_bl));
}
void MainWindow::on_radioButton_b0_4_clicked(){
    register_input_bl[3] = '0';
    ui->b_input_register_l->setText(QString::fromStdString(register_input_bl));
}
void MainWindow::on_radioButton_b0_5_clicked(){
    register_input_bl[2] = '0';
    ui->b_input_register_l->setText(QString::fromStdString(register_input_bl));
}
void MainWindow::on_radioButton_b0_6_clicked(){
    register_input_bl[1] = '0';
    ui->b_input_register_l->setText(QString::fromStdString(register_input_bl));
}
void MainWindow::on_radioButton_b0_7_clicked(){
    register_input_bl[0] = '0';
    ui->b_input_register_l->setText(QString::fromStdString(register_input_bl));
}
void MainWindow::on_radioButton_b0_8_clicked(){
    register_input_bh[7] = '0';
    ui->b_input_register_h->setText(QString::fromStdString(register_input_bh));
}
void MainWindow::on_radioButton_b0_9_clicked(){
    register_input_bh[6] = '0';
    ui->b_input_register_h->setText(QString::fromStdString(register_input_bh));
}
void MainWindow::on_radioButton_b0_10_clicked(){
    register_input_bh[5] = '0';
    ui->b_input_register_h->setText(QString::fromStdString(register_input_bh));
}
void MainWindow::on_radioButton_b0_11_clicked(){
    register_input_bh[4] = '0';
    ui->b_input_register_h->setText(QString::fromStdString(register_input_bh));
}
void MainWindow::on_radioButton_b0_12_clicked(){
    register_input_bh[3] = '0';
    ui->b_input_register_h->setText(QString::fromStdString(register_input_bh));
}
void MainWindow::on_radioButton_b0_13_clicked(){
    register_input_bh[2] = '0';
    ui->b_input_register_h->setText(QString::fromStdString(register_input_bh));
}
void MainWindow::on_radioButton_b0_14_clicked(){
    register_input_bh[1] = '0';
    ui->b_input_register_h->setText(QString::fromStdString(register_input_bh));
}
void MainWindow::on_radioButton_b0_15_clicked(){
    register_input_bh[0] = '0';
    ui->b_input_register_h->setText(QString::fromStdString(register_input_bh));
}

// ---------------------------------------------------------------- C 0
void MainWindow::on_radioButton_c0_0_clicked(){
    register_input_cl[7] = '0';
    ui->c_input_register_l->setText(QString::fromStdString(register_input_cl));
}
void MainWindow::on_radioButton_c0_1_clicked(){
    register_input_cl[6] = '0';
    ui->c_input_register_l->setText(QString::fromStdString(register_input_cl));
}
void MainWindow::on_radioButton_c0_2_clicked(){
    register_input_cl[5] = '0';
    ui->c_input_register_l->setText(QString::fromStdString(register_input_cl));
}
void MainWindow::on_radioButton_c0_3_clicked(){
    register_input_cl[4] = '0';
    ui->c_input_register_l->setText(QString::fromStdString(register_input_cl));
}
void MainWindow::on_radioButton_c0_4_clicked(){
    register_input_cl[3] = '0';
    ui->c_input_register_l->setText(QString::fromStdString(register_input_cl));
}
void MainWindow::on_radioButton_c0_5_clicked(){
    register_input_cl[2] = '0';
    ui->c_input_register_l->setText(QString::fromStdString(register_input_cl));
}
void MainWindow::on_radioButton_c0_6_clicked(){
    register_input_cl[1] = '0';
    ui->c_input_register_l->setText(QString::fromStdString(register_input_cl));
}
void MainWindow::on_radioButton_c0_7_clicked(){
    register_input_cl[0] = '0';
    ui->c_input_register_l->setText(QString::fromStdString(register_input_cl));
}
void MainWindow::on_radioButton_c0_8_clicked(){
    register_input_ch[7] = '0';
    ui->c_input_register_h->setText(QString::fromStdString(register_input_ch));
}
void MainWindow::on_radioButton_c0_9_clicked(){
    register_input_ch[6] = '0';
    ui->c_input_register_h->setText(QString::fromStdString(register_input_ch));
}
void MainWindow::on_radioButton_c0_10_clicked(){
    register_input_ch[5] = '0';
    ui->c_input_register_h->setText(QString::fromStdString(register_input_ch));
}
void MainWindow::on_radioButton_c0_11_clicked(){
    register_input_ch[4] = '0';
    ui->c_input_register_h->setText(QString::fromStdString(register_input_ch));
}
void MainWindow::on_radioButton_c0_12_clicked(){
    register_input_ch[3] = '0';
    ui->c_input_register_h->setText(QString::fromStdString(register_input_ch));
}
void MainWindow::on_radioButton_c0_13_clicked(){
    register_input_ch[2] = '0';
    ui->c_input_register_h->setText(QString::fromStdString(register_input_ch));
}
void MainWindow::on_radioButton_c0_14_clicked(){
    register_input_ch[1] = '0';
    ui->c_input_register_h->setText(QString::fromStdString(register_input_ch));
}
void MainWindow::on_radioButton_c0_15_clicked(){
    register_input_ch[0] = '0';
    ui->c_input_register_h->setText(QString::fromStdString(register_input_ch));
}
// ------------------------------------------------------------------ C 1
void MainWindow::on_radioButton_c1_15_clicked(){
    register_input_ch[0] = '1';
    ui->c_input_register_h->setText(QString::fromStdString(register_input_ch));
}
void MainWindow::on_radioButton_c1_14_clicked(){
    register_input_ch[1] = '1';
    ui->c_input_register_h->setText(QString::fromStdString(register_input_ch));
}
void MainWindow::on_radioButton_c1_13_clicked(){
    register_input_ch[2] = '1';
    ui->c_input_register_h->setText(QString::fromStdString(register_input_ch));
}
void MainWindow::on_radioButton_c1_12_clicked(){
    register_input_ch[3] = '1';
    ui->c_input_register_h->setText(QString::fromStdString(register_input_ch));
}
void MainWindow::on_radioButton_c1_11_clicked(){
    register_input_ch[4] = '1';
    ui->c_input_register_h->setText(QString::fromStdString(register_input_ch));
}
void MainWindow::on_radioButton_c1_10_clicked(){
    register_input_ch[5] = '1';
    ui->c_input_register_h->setText(QString::fromStdString(register_input_ch));
}
void MainWindow::on_radioButton_c1_9_clicked(){
    register_input_ch[6] = '1';
    ui->c_input_register_h->setText(QString::fromStdString(register_input_ch));
}
void MainWindow::on_radioButton_c1_8_clicked(){
    register_input_ch[7] = '1';
    ui->c_input_register_h->setText(QString::fromStdString(register_input_ch));
}
void MainWindow::on_radioButton_c1_7_clicked(){
    register_input_cl[0] = '1';
    ui->c_input_register_l->setText(QString::fromStdString(register_input_cl));
}
void MainWindow::on_radioButton_c1_6_clicked(){
    register_input_cl[1] = '1';
    ui->c_input_register_l->setText(QString::fromStdString(register_input_cl));
}
void MainWindow::on_radioButton_c1_5_clicked(){
    register_input_cl[2] = '1';
    ui->c_input_register_l->setText(QString::fromStdString(register_input_cl));
}
void MainWindow::on_radioButton_c1_4_clicked(){
    register_input_cl[3] = '1';
    ui->c_input_register_l->setText(QString::fromStdString(register_input_cl));
}
void MainWindow::on_radioButton_c1_3_clicked(){
    register_input_cl[4] = '1';
    ui->c_input_register_l->setText(QString::fromStdString(register_input_cl));
}
void MainWindow::on_radioButton_c1_2_clicked(){
    register_input_cl[5] = '1';
    ui->c_input_register_l->setText(QString::fromStdString(register_input_cl));
}
void MainWindow::on_radioButton_c1_1_clicked(){
    register_input_cl[6] = '1';
    ui->c_input_register_l->setText(QString::fromStdString(register_input_cl));
}
void MainWindow::on_radioButton_c1_0_clicked(){
    register_input_cl[7] = '1';
    ui->c_input_register_l->setText(QString::fromStdString(register_input_cl));
}

// ---------------------------------------------------------------- D 0
void MainWindow::on_radioButton_d0_0_clicked(){
    register_input_dl[7] = '0';
    ui->d_input_register_l->setText(QString::fromStdString(register_input_dl));
}
void MainWindow::on_radioButton_d0_1_clicked(){
    register_input_dl[6] = '0';
    ui->d_input_register_l->setText(QString::fromStdString(register_input_dl));
}
void MainWindow::on_radioButton_d0_2_clicked(){
    register_input_dl[5] = '0';
    ui->d_input_register_l->setText(QString::fromStdString(register_input_dl));
}
void MainWindow::on_radioButton_d0_3_clicked(){
    register_input_dl[4] = '0';
    ui->d_input_register_l->setText(QString::fromStdString(register_input_dl));
}
void MainWindow::on_radioButton_d0_4_clicked(){
    register_input_dl[3] = '0';
    ui->d_input_register_l->setText(QString::fromStdString(register_input_dl));
}
void MainWindow::on_radioButton_d0_5_clicked(){
    register_input_dl[2] = '0';
    ui->d_input_register_l->setText(QString::fromStdString(register_input_dl));
}
void MainWindow::on_radioButton_d0_6_clicked(){
    register_input_dl[1] = '0';
    ui->d_input_register_l->setText(QString::fromStdString(register_input_dl));
}
void MainWindow::on_radioButton_d0_7_clicked(){
    register_input_dl[0] = '0';
    ui->d_input_register_l->setText(QString::fromStdString(register_input_dl));
}
void MainWindow::on_radioButton_d0_8_clicked(){
    register_input_dh[7] = '0';
    ui->d_input_register_h->setText(QString::fromStdString(register_input_dh));
}
void MainWindow::on_radioButton_d0_9_clicked(){
    register_input_dh[6] = '0';
    ui->d_input_register_h->setText(QString::fromStdString(register_input_dh));
}
void MainWindow::on_radioButton_d0_10_clicked(){
    register_input_dh[5] = '0';
    ui->d_input_register_h->setText(QString::fromStdString(register_input_dh));
}
void MainWindow::on_radioButton_d0_11_clicked(){
    register_input_dh[4] = '0';
    ui->d_input_register_h->setText(QString::fromStdString(register_input_dh));
}
void MainWindow::on_radioButton_d0_12_clicked(){
    register_input_dh[3] = '0';
    ui->d_input_register_h->setText(QString::fromStdString(register_input_dh));
}
void MainWindow::on_radioButton_d0_13_clicked(){
    register_input_dh[2] = '0';
    ui->d_input_register_h->setText(QString::fromStdString(register_input_dh));
}
void MainWindow::on_radioButton_d0_14_clicked(){
    register_input_dh[1] = '0';
    ui->d_input_register_h->setText(QString::fromStdString(register_input_dh));
}
void MainWindow::on_radioButton_d0_15_clicked(){
    register_input_dh[0] = '0';
    ui->d_input_register_h->setText(QString::fromStdString(register_input_dh));
}
// ------------------------------------------------------------------ D 1
void MainWindow::on_radioButton_d1_15_clicked(){
    register_input_dh[0] = '1';
    ui->d_input_register_h->setText(QString::fromStdString(register_input_dh));
}
void MainWindow::on_radioButton_d1_14_clicked(){
    register_input_dh[1] = '1';
    ui->d_input_register_h->setText(QString::fromStdString(register_input_dh));
}
void MainWindow::on_radioButton_d1_13_clicked(){
    register_input_dh[2] = '1';
    ui->d_input_register_h->setText(QString::fromStdString(register_input_dh));
}
void MainWindow::on_radioButton_d1_12_clicked(){
    register_input_dh[3] = '1';
    ui->d_input_register_h->setText(QString::fromStdString(register_input_dh));
}
void MainWindow::on_radioButton_d1_11_clicked(){
    register_input_dh[4] = '1';
    ui->d_input_register_h->setText(QString::fromStdString(register_input_dh));
}
void MainWindow::on_radioButton_d1_10_clicked(){
    register_input_dh[5] = '1';
    ui->d_input_register_h->setText(QString::fromStdString(register_input_dh));
}
void MainWindow::on_radioButton_d1_9_clicked(){
    register_input_dh[6] = '1';
    ui->d_input_register_h->setText(QString::fromStdString(register_input_dh));
}
void MainWindow::on_radioButton_d1_8_clicked(){
    register_input_dh[7] = '1';
    ui->d_input_register_h->setText(QString::fromStdString(register_input_dh));
}
void MainWindow::on_radioButton_d1_7_clicked(){
    register_input_dl[0] = '1';
    ui->d_input_register_l->setText(QString::fromStdString(register_input_dl));
}
void MainWindow::on_radioButton_d1_6_clicked(){
    register_input_dl[1] = '1';
    ui->d_input_register_l->setText(QString::fromStdString(register_input_dl));
}
void MainWindow::on_radioButton_d1_5_clicked(){
    register_input_dl[2] = '1';
    ui->d_input_register_l->setText(QString::fromStdString(register_input_dl));
}
void MainWindow::on_radioButton_d1_4_clicked(){
    register_input_dl[3] = '1';
    ui->d_input_register_l->setText(QString::fromStdString(register_input_dl));
}
void MainWindow::on_radioButton_d1_3_clicked(){
    register_input_dl[4] = '1';
    ui->d_input_register_l->setText(QString::fromStdString(register_input_dl));
}
void MainWindow::on_radioButton_d1_2_clicked(){
    register_input_dl[5] = '1';
    ui->d_input_register_l->setText(QString::fromStdString(register_input_dl));
}
void MainWindow::on_radioButton_d1_1_clicked(){
    register_input_dl[6] = '1';
    ui->d_input_register_l->setText(QString::fromStdString(register_input_dl));
}
void MainWindow::on_radioButton_d1_0_clicked(){
    register_input_dl[7] = '1';
    ui->d_input_register_l->setText(QString::fromStdString(register_input_dl));
}

void MainWindow::on_wpisz_button_a_clicked(){
    register_al = register_input_al;
    register_ah = register_input_ah;
    ui->a_register_l->setText(QString::fromStdString(register_al));
    ui->a_register_h->setText(QString::fromStdString(register_ah));
}

void MainWindow::on_wpisz_button_c_clicked(){
    register_cl = register_input_cl;
    register_ch = register_input_ch;
    ui->c_register_l->setText(QString::fromStdString(register_cl));
    ui->c_register_h->setText(QString::fromStdString(register_ch));
}

void MainWindow::on_wpisz_button_b_clicked(){
    register_bl = register_input_bl;
    register_bh = register_input_bh;
    ui->b_register_l->setText(QString::fromStdString(register_bl));
    ui->b_register_h->setText(QString::fromStdString(register_bh));
}

void MainWindow::on_wpisz_button_d_clicked(){
    register_dl = register_input_dl;
    register_dh = register_input_dh;
    ui->d_register_l->setText(QString::fromStdString(register_dl));
    ui->d_register_h->setText(QString::fromStdString(register_dh));
}

void MainWindow::on_combo_box_order_currentIndexChanged(int index)
{
    int chosen_order = ui->combo_box_order->currentIndex();
    if(chosen_order == SUB){
        ui->label_one->setText("-");
        ui->label_two->setEnabled(true);
        ui->label_two->setText("=>");
        ui->combo_box_three->setEnabled(true);
    }else if(chosen_order == ADD){
        ui->label_one->setText("+");
        ui->label_two->setEnabled(true);
        ui->label_two->setText("=>");
        ui->combo_box_three->setEnabled(true);
    }else{  // MOV
        ui->label_one->setText("=>");
        ui->label_two->setText("");
        ui->label_two->setEnabled(false);
        ui->combo_box_three->setCurrentText("");
        ui->combo_box_three->setEnabled(false);
    }

    /*  sprawdzanie jakie numery mają które ordery
    QString s = QString::number(chosen_order);
    ui->label_one->setText(s);
    */
}

void MainWindow::on_perform_order_button_clicked(){
    int order = ui->combo_box_order->currentIndex();
    if(order == MOV){   // ================================= PRZENOSZENIE
        std::string from_h, from_l;
        if(ui->combo_box_one->currentText() == "A"){
            from_h = register_ah;
            from_l = register_al;
        }else if(ui->combo_box_one->currentText() == "B"){
            from_h = register_bh;
            from_l = register_bl;
        }else if(ui->combo_box_one->currentText() == "C"){
            from_h = register_ch;
            from_l = register_cl;
        }else if(ui->combo_box_one->currentText() == "D"){
            from_h = register_dh;
            from_l = register_dl;
        }else{
            ui->combo_box_one->setCurrentText("ERROR");
        }
        if(ui->combo_box_two->currentText() == "A"){
            register_ah = from_h;
            register_al = from_l;
            ui->a_register_l->setText(QString::fromStdString(register_al));
            ui->a_register_h->setText(QString::fromStdString(register_ah));
        }else if(ui->combo_box_two->currentText() == "B"){
            register_bh = from_h;
            register_bl = from_l;
            ui->b_register_l->setText(QString::fromStdString(register_bl));
            ui->b_register_h->setText(QString::fromStdString(register_bh));
        }else if(ui->combo_box_two->currentText() == "C"){
            register_ch = from_h;
            register_cl = from_l;
            ui->c_register_l->setText(QString::fromStdString(register_cl));
            ui->c_register_h->setText(QString::fromStdString(register_ch));
        }else if(ui->combo_box_two->currentText() == "D"){
            register_dh = from_h;
            register_dl = from_l;
            ui->d_register_l->setText(QString::fromStdString(register_dl));
            ui->d_register_h->setText(QString::fromStdString(register_dh));
        }else{
            ui->combo_box_two->setCurrentText("ERROR");
        }

    }else if(order == ADD){ // =========================== DODAWANIE
        std::string first, second, answer;
        if(ui->combo_box_one->currentText() == "A"){
            first = register_ah + register_al;
        }else if(ui->combo_box_one->currentText() == "B"){
            first = register_bh + register_bl;
        }else if(ui->combo_box_one->currentText() == "C"){
            first = register_ch + register_cl;
        }else if(ui->combo_box_one->currentText() == "D"){
            first = register_dh + register_dl;
        }else{
            ui->combo_box_one->setCurrentText("ERROR");
        }
        if(ui->combo_box_two->currentText() == "A"){
            second = register_ah + register_al;
        }else if(ui->combo_box_two->currentText() == "B"){
            second = register_bh + register_bl;
        }else if(ui->combo_box_two->currentText() == "C"){
            second = register_ch + register_cl;
        }else if(ui->combo_box_two->currentText() == "D"){
            second = register_dh + register_dl;
        }else{
            ui->combo_box_two->setCurrentText("ERROR");
        }
        if(ui->combo_box_three->currentText() == "A"){
            answer = addBinary(first, second);
            register_ah = "";
            register_al = "";
            if(answer.size() == 16){
                for(int i = 0; i < 8; i++)
                    register_ah = register_ah + answer[i];
                for(int i = 8; i < 16; i++)
                    register_al = register_al + answer[i];
            }else if(answer.size() == 17){  // ============================ w przypadku przepełnienia tracimy 'wystającą' poza rejestr jedynkę
                for(int i = 1; i < 9; i++)
                    register_ah = register_ah + answer[i];
                for(int i = 9; i < 17; i++)
                    register_al = register_al + answer[i];
            }else{
                register_ah = "ERROR";
                register_al = "ERROR";
            }
            ui->a_register_l->setText(QString::fromStdString(register_al));
            ui->a_register_h->setText(QString::fromStdString(register_ah));
        }else if(ui->combo_box_three->currentText() == "B"){
            answer = addBinary(first, second);
            register_bh = "";
            register_bl = "";
            if(answer.size() == 16){
                for(int i = 0; i < 8; i++)
                    register_bh = register_bh + answer[i];
                for(int i = 8; i < 16; i++)
                    register_bl = register_bl + answer[i];
            }else if(answer.size() == 17){  // ============================ w przypadku przepełnienia tracimy 'wystającą' poza rejestr jedynkę
                for(int i = 1; i < 9; i++)
                    register_bh = register_bh + answer[i];
                for(int i = 9; i < 17; i++)
                    register_bl = register_bl + answer[i];
            }else{
                register_bh = "ERROR";
                register_bl = "ERROR";
            }
            ui->b_register_l->setText(QString::fromStdString(register_bl));
            ui->b_register_h->setText(QString::fromStdString(register_bh));
        }else if(ui->combo_box_three->currentText() == "C"){
            answer = addBinary(first, second);
            register_ch = "";
            register_cl = "";
            if(answer.size() == 16){
                for(int i = 0; i < 8; i++)
                    register_ch = register_ch + answer[i];
                for(int i = 8; i < 16; i++)
                    register_cl = register_cl + answer[i];
            }else if(answer.size() == 17){  // ============================ w przypadku przepełnienia tracimy 'wystającą' poza rejestr jedynkę
                for(int i = 1; i < 9; i++)
                    register_ch = register_ch + answer[i];
                for(int i = 9; i < 17; i++)
                    register_cl = register_cl + answer[i];
            }else{
                register_ch = "ERROR";
                register_cl = "ERROR";
            }
            ui->c_register_l->setText(QString::fromStdString(register_cl));
            ui->c_register_h->setText(QString::fromStdString(register_ch));
        }else if(ui->combo_box_three->currentText() == "D"){
            answer = addBinary(first, second);
            register_dh = "";
            register_dl = "";
            if(answer.size() == 16){
                for(int i = 0; i < 8; i++)
                    register_dh = register_dh + answer[i];
                for(int i = 8; i < 16; i++)
                    register_dl = register_dl + answer[i];
            }else if(answer.size() == 17){  // ============================ w przypadku przepełnienia tracimy 'wystającą' poza rejestr jedynkę
                for(int i = 1; i < 9; i++)
                    register_dh = register_dh + answer[i];
                for(int i = 9; i < 17; i++)
                    register_dl = register_dl + answer[i];
            }else{
                register_dh = "ERROR";
                register_dl = "ERROR";
            }
            ui->d_register_l->setText(QString::fromStdString(register_dl));
            ui->d_register_h->setText(QString::fromStdString(register_dh));
        }else{
            ui->combo_box_three->setCurrentText("ERROR");
        }
    }else{  // ============================ ODEJMOWANIE

    }
}
