#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>
#include <iostream>
#include <cstdio>       // do rename() i remove()
#include <QFile>        // do zapisywania w pliku   |
#include <QTextStream>  // do zapisywania w pliku   |
#include <QMessageBox>
#include <QThread>      // delay in performing whole program
#include <direct.h>     // _getcwd() znajdowanie current directory
#include <QInputDialog> // dla okienek pobierających text od użytkownika
#include <QDir>         // QDir jest używany przy okienkach pobierającyh text od użytkownika
#include <fstream>      // std::ofstream()

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

std::string get_current_dir(){
    char buff[FILENAME_MAX]; //create string buffer to hold path
    _getcwd( buff, FILENAME_MAX );
    std::string current_working_dir(buff);

    return current_working_dir;
}

std::string get_current_dir(std::string show_msgBox){
    char buff[FILENAME_MAX]; //create string buffer to hold path
    _getcwd( buff, FILENAME_MAX );
    std::string current_working_dir(buff);

    if(show_msgBox == "show"){
        QMessageBox msgBox;
        msgBox.setText(QString::fromStdString(current_working_dir));
        msgBox.exec();
    }
    return current_working_dir;
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

std::string decimal_to_binary(int x){

    int x_cpy = x;
    std::string ans = "0000000000000000";    // 16 bitów
    std::string ans_backwards = "";

    while(x_cpy != 0){
        if(x_cpy%2 == 1)
            ans_backwards = ans_backwards + "1";
        else if(x_cpy%2 == 0)
            ans_backwards = ans_backwards + "0";
        else
            std::cout << "error -> modulo z 2 inne niż 1 lub 0";
        x_cpy = x_cpy/2;
    }

    for(int i = ans_backwards.length(); i>=0; i--){
        // std::cout << ans_backwards[i];
    }

    int k = 0;
    for(int i = ans.length()-1; i >= (ans.length() - ans_backwards.length()); i--){
        ans[i] = ans_backwards[k];
        k++;
    }

    return ans;
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

// ---------------------------------------------------  wpisywanie argumentu dla trybu natychmiastowego
void MainWindow::on_radioButton_in1_15_clicked(){
    input_h[0] = '1';
    ui->in_register_h->setText(QString::fromStdString(input_h));
}
void MainWindow::on_radioButton_in1_14_clicked(){
    input_h[1] = '1';
    ui->in_register_h->setText(QString::fromStdString(input_h));
}
void MainWindow::on_radioButton_in1_13_clicked(){
    input_h[2] = '1';
    ui->in_register_h->setText(QString::fromStdString(input_h));
}
void MainWindow::on_radioButton_in1_12_clicked(){
    input_h[3] = '1';
    ui->in_register_h->setText(QString::fromStdString(input_h));
}
void MainWindow::on_radioButton_in1_11_clicked(){
    input_h[4] = '1';
    ui->in_register_h->setText(QString::fromStdString(input_h));
}
void MainWindow::on_radioButton_in1_10_clicked(){
    input_h[5] = '1';
    ui->in_register_h->setText(QString::fromStdString(input_h));
}
void MainWindow::on_radioButton_in1_9_clicked(){
    input_h[6] = '1';
    ui->in_register_h->setText(QString::fromStdString(input_h));
}
void MainWindow::on_radioButton_in1_8_clicked(){
    input_h[7] = '1';
    ui->in_register_h->setText(QString::fromStdString(input_h));
}
void MainWindow::on_radioButton_in1_7_clicked(){
    input_l[0] = '1';
    ui->in_register_l->setText(QString::fromStdString(input_l));
}
void MainWindow::on_radioButton_in1_6_clicked(){
    input_l[1] = '1';
    ui->in_register_l->setText(QString::fromStdString(input_l));
}
void MainWindow::on_radioButton_in1_5_clicked(){
    input_l[2] = '1';
    ui->in_register_l->setText(QString::fromStdString(input_l));
}
void MainWindow::on_radioButton_in1_4_clicked(){
    input_l[3] = '1';
    ui->in_register_l->setText(QString::fromStdString(input_l));
}
void MainWindow::on_radioButton_in1_3_clicked(){
    input_l[4] = '1';
    ui->in_register_l->setText(QString::fromStdString(input_l));
}
void MainWindow::on_radioButton_in1_2_clicked(){
    input_l[5] = '1';
    ui->in_register_l->setText(QString::fromStdString(input_l));
}
void MainWindow::on_radioButton_in1_1_clicked(){
    input_l[6] = '1';
    ui->in_register_l->setText(QString::fromStdString(input_l));
}
void MainWindow::on_radioButton_in1_0_clicked(){
    input_l[7] = '1';
    ui->in_register_l->setText(QString::fromStdString(input_l));
}
void MainWindow::on_radioButton_in0_15_clicked(){
    input_h[0] = '0';
    ui->in_register_h->setText(QString::fromStdString(input_h));
}
void MainWindow::on_radioButton_in0_14_clicked(){
    input_h[1] = '0';
    ui->in_register_h->setText(QString::fromStdString(input_h));
}
void MainWindow::on_radioButton_in0_13_clicked(){
    input_h[2] = '0';
    ui->in_register_h->setText(QString::fromStdString(input_h));
}
void MainWindow::on_radioButton_in0_12_clicked(){
    input_h[3] = '0';
    ui->in_register_h->setText(QString::fromStdString(input_h));
}
void MainWindow::on_radioButton_in0_11_clicked(){
    input_h[4] = '0';
    ui->in_register_h->setText(QString::fromStdString(input_h));
}
void MainWindow::on_radioButton_in0_10_clicked(){
    input_h[5] = '0';
    ui->in_register_h->setText(QString::fromStdString(input_h));
}
void MainWindow::on_radioButton_in0_9_clicked(){
    input_h[6] = '0';
    ui->in_register_h->setText(QString::fromStdString(input_h));
}
void MainWindow::on_radioButton_in0_8_clicked(){
    input_h[7] = '0';
    ui->in_register_h->setText(QString::fromStdString(input_h));
}
void MainWindow::on_radioButton_in0_7_clicked(){
    input_l[0] = '0';
    ui->in_register_l->setText(QString::fromStdString(input_l));
}
void MainWindow::on_radioButton_in0_6_clicked(){
    input_l[1] = '0';
    ui->in_register_l->setText(QString::fromStdString(input_l));
}
void MainWindow::on_radioButton_in0_5_clicked(){
    input_l[2] = '0';
    ui->in_register_l->setText(QString::fromStdString(input_l));
}
void MainWindow::on_radioButton_in0_4_clicked(){
    input_l[3] = '0';
    ui->in_register_l->setText(QString::fromStdString(input_l));
}
void MainWindow::on_radioButton_in0_3_clicked(){
    input_l[4] = '0';
    ui->in_register_l->setText(QString::fromStdString(input_l));
}
void MainWindow::on_radioButton_in0_2_clicked(){
    input_l[5] = '0';
    ui->in_register_l->setText(QString::fromStdString(input_l));
}
void MainWindow::on_radioButton_in0_1_clicked(){
    input_l[6] = '0';
    ui->in_register_l->setText(QString::fromStdString(input_l));
}
void MainWindow::on_radioButton_in0_0_clicked(){
    input_l[7] = '0';
    ui->in_register_l->setText(QString::fromStdString(input_l));
}


void MainWindow::on_combo_box_order_currentIndexChanged(int index)
{
    // ----------- resetowanie komunikatów błedów
    ui->label_result_less_than_zero->setGeometry(680, 330, 121, 1);
    ui->label_order_limit_reached->setGeometry(480, 590, 281, 1);

    if(ui->combo_box_order->currentText() == "SUB"){
        ui->label_one->setText("-");
        ui->label_two->setEnabled(true);
        ui->label_two->setText("=>");
        ui->combo_box_one->setEnabled(true);
        ui->combo_box_two->setEnabled(true);
        ui->combo_box_three->setEnabled(true);
        if(ui->combo_box_two->currentText() == "INPUT"){
            ui->label_two->setEnabled(false);
            ui->combo_box_three->setEnabled(false);
        }
    }else if(ui->combo_box_order->currentText() == "ADD"){
        ui->label_one->setText("+");
        ui->label_two->setEnabled(true);
        ui->label_two->setText("=>");
        ui->combo_box_one->setEnabled(true);
        ui->combo_box_two->setEnabled(true);
        ui->combo_box_three->setEnabled(true);
        if(ui->combo_box_two->currentText() == "INPUT"){
            ui->label_two->setEnabled(false);
            ui->combo_box_three->setEnabled(false);
        }
    }else if(ui->combo_box_order->currentText() == "INT 00H"){
        ui->label_two->setEnabled(false);
        ui->combo_box_one->setEnabled(false);
        ui->combo_box_two->setEnabled(false);
        ui->combo_box_three->setEnabled(false);
    }else if(ui->combo_box_order->currentText() == "INT 2AH"){
        ui->label_two->setEnabled(false);
        ui->combo_box_one->setEnabled(false);
        ui->combo_box_two->setEnabled(false);
        ui->combo_box_three->setEnabled(false);
    }else if(ui->combo_box_order->currentText() == "INT 2CH"){
        ui->label_two->setEnabled(false);
        ui->combo_box_one->setEnabled(false);
        ui->combo_box_two->setEnabled(false);
        ui->combo_box_three->setEnabled(false);
    }else if(ui->combo_box_order->currentText() == "PUSH"){
        ui->label_two->setEnabled(false);
        ui->combo_box_one->setEnabled(true);
        ui->combo_box_two->setEnabled(false);
        ui->combo_box_three->setEnabled(false);
    }else if(ui->combo_box_order->currentText() == "POP"){
        ui->label_two->setEnabled(false);
        ui->combo_box_one->setEnabled(true);
        ui->combo_box_two->setEnabled(false);
        ui->combo_box_three->setEnabled(false);
    }else if(ui->combo_box_order->currentText() == "INT 0DH"){
        ui->label_two->setEnabled(false);
        ui->combo_box_one->setEnabled(false);
        ui->combo_box_two->setEnabled(false);
        ui->combo_box_three->setEnabled(false);
    }else if(ui->combo_box_order->currentText() == "INT 41H"){
        ui->label_two->setEnabled(false);
        ui->combo_box_one->setEnabled(false);
        ui->combo_box_two->setEnabled(false);
        ui->combo_box_three->setEnabled(false);
    }else if(ui->combo_box_order->currentText() == "INT 47H"){
        ui->label_two->setEnabled(false);
        ui->combo_box_one->setEnabled(false);
        ui->combo_box_two->setEnabled(false);
        ui->combo_box_three->setEnabled(false);
    }else if(ui->combo_box_order->currentText() == "INT 56H"){
        ui->label_two->setEnabled(false);
        ui->combo_box_one->setEnabled(false);
        ui->combo_box_two->setEnabled(false);
        ui->combo_box_three->setEnabled(false);
    }else if(ui->combo_box_order->currentText() == "INT 48H"){
        ui->label_two->setEnabled(false);
        ui->combo_box_one->setEnabled(true);
        ui->combo_box_two->setEnabled(false);
        ui->combo_box_three->setEnabled(false);
    }else if(ui->combo_box_order->currentText() == "INT 49H"){
        ui->label_two->setEnabled(false);
        ui->combo_box_one->setEnabled(false);
        ui->combo_box_two->setEnabled(false);
        ui->combo_box_three->setEnabled(false);
    }else if(ui->combo_box_order->currentText() == "INT 4AH"){
        ui->label_two->setEnabled(false);
        ui->combo_box_one->setEnabled(true);
        ui->combo_box_two->setEnabled(false);
        ui->combo_box_three->setEnabled(false);
    }else{  // MOV
        if(ui->combo_box_two->currentText() == "INPUT"){
            ui->label_one->setText("<=");
        }else{
            ui->label_one->setText("=>");
        }
        ui->label_two->setText("");
        ui->label_two->setEnabled(false);
        ui->combo_box_three->setCurrentText("");
        ui->combo_box_one->setEnabled(true);
        ui->combo_box_two->setEnabled(true);
        ui->combo_box_three->setEnabled(false);
    }

    /*  sprawdzanie jakie numery mają które ordery
    QString s = QString::number(chosen_order);
    ui->label_one->setText(s);
    */
}


void MainWindow::on_combo_box_two_currentIndexChanged(int index)
{
    // ----------- resetowanie komunikatów błedów
    ui->label_result_less_than_zero->setGeometry(680, 330, 121, 1);
    ui->label_order_limit_reached->setGeometry(480, 590, 281, 1);

    if(ui->combo_box_two->currentText() == "INPUT" && ui->combo_box_order->currentText() == "MOV"){
        ui->label_one->setText("<=");
    }else if(ui->combo_box_two->currentText() != "INPUT" && ui->combo_box_order->currentText() == "MOV")
        ui->label_one->setText("=>");
    if(ui->combo_box_two->currentText() == "INPUT"){
        ui->label_two->setEnabled(false);
        ui->combo_box_three->setEnabled(false);
    }
    if(ui->combo_box_two->currentText() != "INPUT" && ui->combo_box_order->currentText() != "MOV"){ // gdy np. ADD, przy zmianie z INPUT na np. C rejestr wynikowy nie robił się enable
        ui->label_two->setEnabled(true);
        ui->combo_box_three->setEnabled(true);
    }
}


void MainWindow::on_perform_order_button_clicked(){

    ui->label_result_less_than_zero->setGeometry(680, 330, 121, 1);
    ui->label_order_limit_reached->setGeometry(480, 590, 281, 1);

    if(ui->combo_box_order->currentText() == "MOV"){   // ================================= PRZENOSZENIE
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
        }else if(ui->combo_box_two->currentText() == "INPUT"){
            if(ui->combo_box_one->currentText() == "A"){
                register_ah = input_h;
                register_al = input_l;
                ui->a_register_l->setText(QString::fromStdString(register_al));
                ui->a_register_h->setText(QString::fromStdString(register_ah));
            }else if(ui->combo_box_one->currentText() == "B"){
                register_bh = input_h;
                register_bl = input_l;
                ui->b_register_l->setText(QString::fromStdString(register_bl));
                ui->b_register_h->setText(QString::fromStdString(register_bh));
            }else if(ui->combo_box_one->currentText() == "C"){
                register_ch = input_h;
                register_cl = input_l;
                ui->c_register_l->setText(QString::fromStdString(register_cl));
                ui->c_register_h->setText(QString::fromStdString(register_ch));
            }else if(ui->combo_box_one->currentText() == "D"){
                register_dh = input_h;
                register_dl = input_l;
                ui->d_register_l->setText(QString::fromStdString(register_dl));
                ui->d_register_h->setText(QString::fromStdString(register_dh));
            }else{
                ui->combo_box_one->setCurrentText("ERROR");
            }
        }else{
            ui->combo_box_two->setCurrentText("ERROR");
        }

    }else if(ui->combo_box_order->currentText() == "ADD"){ // =========================== DODAWANIE
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
        if(ui->combo_box_two->currentText() == "INPUT"){    // =============== INPUT - tryb adresowania natychmiastowego
            second = input_h + input_l;

            if(ui->combo_box_one->currentText() == "A"){
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
            }else if(ui->combo_box_one->currentText() == "B"){
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
            }else if(ui->combo_box_one->currentText() == "C"){
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
            }else if(ui->combo_box_one->currentText() == "D"){
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
                ui->combo_box_one->setCurrentText("ERROR");
            }

        }else{    // =========================================== nie input - tryb adresowania rejestrowego
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
        }

    }else if(ui->combo_box_order->currentText() == "SUB"){  // ===================================================== ODEJMOWANIE
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
        if(ui->combo_box_two->currentText() == "INPUT"){    // ====================== INPUT - tryb adresowania natychmiastowego
            second = input_h + input_l;

            int first_int = binary_to_int(first);
            int second_int = binary_to_int(second);

            if(first_int < second_int){
                ui->label_result_less_than_zero->setGeometry(680, 330, 121, 71);
            }

            int answer_int = first_int - second_int;
            answer = decimal_to_binary(answer_int);

            if(ui->combo_box_one->currentText() == "A"){

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

            }else if(ui->combo_box_one->currentText() == "B"){

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

            }else if(ui->combo_box_one->currentText() == "C"){

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

            }else if(ui->combo_box_one->currentText() == "D"){

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

            }

        }else{    // ================================================================ NIE input - tryb adresowania rejestrowego
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
                // std::cout << "\n\nfirst: " << first;
                // std::cout << "\nsecond: " << first;

                // int binary_to_int(std::string input)
                int first_int = binary_to_int(first);
                int second_int = binary_to_int(second);
                // std::cout << "\nfirst_int: " << first_int;
                // std::cout << "\nsecond_int: " << second_int;

                if(first_int < second_int){
                    ui->label_result_less_than_zero->setGeometry(680, 330, 121, 71);
                }

                // odejmowanie intów
                int answer_int = first_int - second_int;
                // std::cout << "\nanswer_int: " << answer_int;

                answer = decimal_to_binary(answer_int);
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
                int first_int = binary_to_int(first);
                int second_int = binary_to_int(second);

                if(first_int < second_int){
                    ui->label_result_less_than_zero->setGeometry(680, 330, 121, 71);
                }

                int answer_int = first_int - second_int;
                answer = decimal_to_binary(answer_int);


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
                int first_int = binary_to_int(first);
                int second_int = binary_to_int(second);

                if(first_int < second_int){
                    ui->label_result_less_than_zero->setGeometry(680, 330, 121, 71);
                }

                int answer_int = first_int - second_int;
                answer = decimal_to_binary(answer_int);


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

                int first_int = binary_to_int(first);
                int second_int = binary_to_int(second);

                if(first_int < second_int){
                    ui->label_result_less_than_zero->setGeometry(680, 330, 121, 71);
                }

                int answer_int = first_int - second_int;
                answer = decimal_to_binary(answer_int);


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
        }

    }else if(ui->combo_box_order->currentText() == "INT 00H"){  // ===================================================== ZAKOŃCZ PROGRAM
        QCoreApplication::quit();
    }else if(ui->combo_box_order->currentText() == "INT 2AH"){  // ===================================================== POBIERZ DATĘ
        // current date/time based on current system
        time_t now = time(NULL);
        tm *ltm = localtime(&now);

        int year    = 1900 + ltm->tm_year;
        int month   = 1 + ltm->tm_mon;
        int day     = ltm->tm_mday;

        std::string data_str = decimal_to_binary(year);
        register_ch = "";
        register_cl = "";
        for(int i = 0; i < 8; i++)
            register_ch = register_ch + data_str[i];
        for(int i = 8; i < 16; i++)
            register_cl = register_cl + data_str[i];
        ui->c_register_l->setText(QString::fromStdString(register_cl));
        ui->c_register_h->setText(QString::fromStdString(register_ch));

        data_str = decimal_to_binary(month);
        register_dh = "";
        register_dl = "";
        for(int i = 8; i < 16; i++)
            register_dh = register_dh + data_str[i];
        ui->d_register_h->setText(QString::fromStdString(register_dh));

        data_str = decimal_to_binary(day);
        for(int i = 8; i < 16; i++)
            register_dl = register_dl + data_str[i];
        ui->d_register_l->setText(QString::fromStdString(register_dl));

        /*
        char str[20];
        sprintf(str, "%02d.%02d.%04d", day, month, year);

        QMessageBox msgBox;
        msgBox.setText(str);
        msgBox.exec();
        */
    }else if(ui->combo_box_order->currentText() == "INT 2CH"){  // ===================================================== POBIERZ CZAS
        // current date/time based on current system
        time_t now = time(NULL);
        tm *ltm = localtime(&now);

        int hour    = ltm->tm_hour;
        int minute  = ltm->tm_min;
        int second  = ltm->tm_sec;

        register_ch = "";
        register_cl = "";
        register_dh = "";

        std::string time_str = decimal_to_binary(hour);

        for(int i = 8; i < 16; i++)
            register_ch = register_ch + time_str[i];
        ui->c_register_h->setText(QString::fromStdString(register_ch));

        time_str = decimal_to_binary(minute);
        for(int i = 8; i < 16; i++)
            register_cl = register_cl + time_str[i];
        ui->c_register_l->setText(QString::fromStdString(register_cl));

        time_str = decimal_to_binary(second);
        for(int i = 8; i < 16; i++)
            register_dh = register_dh + time_str[i];
        ui->d_register_h->setText(QString::fromStdString(register_dh));

        /*
        char str[20];
        sprintf(str, "%02d:%02d:%02d", hour, minute, second);

        QMessageBox msgBox;
        msgBox.setText(str);
        msgBox.exec();
        */
    }else if(ui->combo_box_order->currentText() == "PUSH"){     // ===================================================== WSTAW NA STOS
        std::string push_str;

        if(ui->combo_box_one->currentText() == "A"){
            push_str = register_ah + register_al;
        }else if(ui->combo_box_one->currentText() == "B"){
            push_str = register_bh + register_bl;
        }else if(ui->combo_box_one->currentText() == "C"){
            push_str = register_ch + register_cl;
        }else if(ui->combo_box_one->currentText() == "D"){
            push_str = register_dh + register_dl;
        }else{
            ui->combo_box_one->setCurrentText("ERROR");
        }

        int push_int = binary_to_int(push_str);
        stack[stack_ptr] = push_int;
        stack_ptr--;

    }else if(ui->combo_box_order->currentText() == "POP"){      // ===================================================== ZDEJMIJ ZE STOSU
        stack_ptr++;
        int pop_int = stack[stack_ptr];
        std::string pop_str = decimal_to_binary(pop_int);

        if(ui->combo_box_one->currentText() == "A"){

            register_ah = "";
            register_al = "";
            if(pop_str.size() == 16){
                for(int i = 0; i < 8; i++)
                    register_ah = register_ah + pop_str[i];
                for(int i = 8; i < 16; i++)
                    register_al = register_al + pop_str[i];
            }else if(pop_str.size() == 17){  // ============================ w przypadku przepełnienia tracimy 'wystającą' poza rejestr jedynkę
                for(int i = 1; i < 9; i++)
                    register_ah = register_ah + pop_str[i];
                for(int i = 9; i < 17; i++)
                    register_al = register_al + pop_str[i];
            }else{
                register_ah = "ERROR";
                register_al = "ERROR";
            }
            ui->a_register_l->setText(QString::fromStdString(register_al));
            ui->a_register_h->setText(QString::fromStdString(register_ah));

        }else if(ui->combo_box_one->currentText() == "B"){

            register_bh = "";
            register_bl = "";
            if(pop_str.size() == 16){
                for(int i = 0; i < 8; i++)
                    register_bh = register_bh + pop_str[i];
                for(int i = 8; i < 16; i++)
                    register_bl = register_bl + pop_str[i];
            }else if(pop_str.size() == 17){  // ============================ w przypadku przepełnienia tracimy 'wystającą' poza rejestr jedynkę
                for(int i = 1; i < 9; i++)
                    register_bh = register_bh + pop_str[i];
                for(int i = 9; i < 17; i++)
                    register_bl = register_bl + pop_str[i];
            }else{
                register_bh = "ERROR";
                register_bl = "ERROR";
            }
            ui->b_register_l->setText(QString::fromStdString(register_bl));
            ui->b_register_h->setText(QString::fromStdString(register_bh));

        }else if(ui->combo_box_one->currentText() == "C"){

            register_ch = "";
            register_cl = "";
            if(pop_str.size() == 16){
                for(int i = 0; i < 8; i++)
                    register_ch = register_ch + pop_str[i];
                for(int i = 8; i < 16; i++)
                    register_cl = register_cl + pop_str[i];
            }else if(pop_str.size() == 17){  // ============================ w przypadku przepełnienia tracimy 'wystającą' poza rejestr jedynkę
                for(int i = 1; i < 9; i++)
                    register_ch = register_ch + pop_str[i];
                for(int i = 9; i < 17; i++)
                    register_cl = register_cl + pop_str[i];
            }else{
                register_ch = "ERROR";
                register_cl = "ERROR";
            }
            ui->c_register_l->setText(QString::fromStdString(register_cl));
            ui->c_register_h->setText(QString::fromStdString(register_ch));

        }else if(ui->combo_box_one->currentText() == "D"){

            register_dh = "";
            register_dl = "";
            if(pop_str.size() == 16){
                for(int i = 0; i < 8; i++)
                    register_dh = register_dh + pop_str[i];
                for(int i = 8; i < 16; i++)
                    register_dl = register_dl + pop_str[i];
            }else if(pop_str.size() == 17){  // ============================ w przypadku przepełnienia tracimy 'wystającą' poza rejestr jedynkę
                for(int i = 1; i < 9; i++)
                    register_dh = register_dh + pop_str[i];
                for(int i = 9; i < 17; i++)
                    register_dl = register_dl + pop_str[i];
            }else{
                register_dh = "ERROR";
                register_dl = "ERROR";
            }
            ui->d_register_l->setText(QString::fromStdString(register_dl));
            ui->d_register_h->setText(QString::fromStdString(register_dh));

        }else{
            ui->combo_box_one->setCurrentText("ERROR");
        }
    }else if(ui->combo_box_order->currentText() == "INT 0DH"){  // ===================================================== RESET DYSKU
        // zeruj rejestry i program

        // kasuj zawartość pliku z programem
        std::ofstream ofs;
        ofs.open(program_file_name, std::ofstream::out | std::ofstream::trunc);
        ofs.close();

        // zeruj zawartośc rejestrów
        register_al = "00000000";
        register_ah = "00000000";
        ui->a_register_l->setText(QString::fromStdString(register_al));
        ui->a_register_h->setText(QString::fromStdString(register_ah));

        register_cl = "00000000";
        register_ch = "00000000";
        ui->c_register_l->setText(QString::fromStdString(register_cl));
        ui->c_register_h->setText(QString::fromStdString(register_ch));

        register_bl = "00000000";
        register_bh = "00000000";
        ui->b_register_l->setText(QString::fromStdString(register_bl));
        ui->b_register_h->setText(QString::fromStdString(register_bh));

        register_dl = "00000000";
        register_dh = "00000000";
        ui->d_register_l->setText(QString::fromStdString(register_dl));
        ui->d_register_h->setText(QString::fromStdString(register_dh));

    }else if(ui->combo_box_order->currentText() == "INT 41H"){  // ===================================================== KASUJ PLIK (plik programu)
        // remove("filename.txt")
        const char *filename = program_file_name.c_str();

        std::remove(filename);


    }else if(ui->combo_box_order->currentText() == "INT 47H"){  // ===================================================== POBIERZ AKTUALNY KATALOG/DIRECTORY
        // getcwd(buff, filename)
        get_current_dir("show");

    }else if(ui->combo_box_order->currentText() == "INT 56H"){  // ===================================================== ZMIEŃ NAZWĘ PLIKU (plik programu)
        // rename(oldname, newname)
        bool ok;
        QString text = QInputDialog::getText(this, tr("Okno nowej nazwy pliku programu"),
                                                 tr("nowa nazwa pliku programu:"), QLineEdit::Normal,
                                                 QDir::home().dirName(), &ok);

        if (ok && !text.isEmpty()){
            if(text.contains(".txt", Qt::CaseSensitive)){
                // text kończy się ".txt" to nie dokładaj ".txt"
            }else{
                // dodaj ".txt" na końcu nowej nazwy pliku otrzymanej od użytkownika
                text = text + ".txt";
            }

            //konwersja z std::string lub Qstring na const char*
            const char *c_old_name = program_file_name.c_str();

            QByteArray ba = text.toLocal8Bit();
            const char *c_new_name = ba.data();

            std::rename(c_old_name, c_new_name);
            program_file_name = text.toStdString();

        }

    }else if(ui->combo_box_order->currentText() == "INT 48H"){  // ===================================================== ALOKUJ BLOK PAMIĘCI
        // <list> push_front(ah + al)

        if(ui->combo_box_one->currentText() == "A"){
            memory_blocks.push_front(register_ah + register_al);
        }else if(ui->combo_box_one->currentText() == "B"){
            memory_blocks.push_front(register_bh + register_bl);
        }else if(ui->combo_box_one->currentText() == "C"){
            memory_blocks.push_front(register_ch + register_cl);
        }else if(ui->combo_box_one->currentText() == "D"){
            memory_blocks.push_front(register_dh + register_dl);
        }else{
            std::cout << "ERROR INT 48H: Nie udalo sie utworzyc nowego bloku pamieci\n";
        }

    }else if(ui->combo_box_order->currentText() == "INT 49H"){  // ===================================================== ZWOLNIJ ZAALOKOWANĄ PAMIĘĆ
        // <list> clear()
        memory_blocks.clear();


    }else if(ui->combo_box_order->currentText() == "INT 4AH"){  // ===================================================== MODYFIKUJ ZAALOKOWANE BLOKI PAMIĘCI
        // for(list.size): list[i] = "new content"

        // counter = 0;
        // if(empty == false){
        //    counter++;
        //    pop_back()
        // }
        // for(counter){
        //    push_front(A/B/C/D)

        uint8_t counter = 0;    // max 256

        while(memory_blocks.empty() == false){
            counter++;
            memory_blocks.pop_back();
        }

        for(uint8_t i = 0; i < counter; i++){

            if(ui->combo_box_one->currentText() == "A"){
                memory_blocks.push_front(register_ah + register_al);
            }else if(ui->combo_box_one->currentText() == "B"){
                memory_blocks.push_front(register_bh + register_bl);
            }else if(ui->combo_box_one->currentText() == "C"){
                memory_blocks.push_front(register_ch + register_cl);
            }else if(ui->combo_box_one->currentText() == "D"){
                memory_blocks.push_front(register_dh + register_dl);
            }else{
                std::cout << "ERROR INT 4AH: Nie udalo sie wstawic zamiennego bloku pamieci\n";
            }

        }


    }else{
        ui->combo_box_order->setCurrentText("ERROR");
    }
}


void MainWindow::display_program(){
    // ----------- przerabianie tablicy programu z rozkazami na string do wyświetlenia
    program_str = "";
    for(int i = 0; i < how_many_orders; i++){
        if(program[i].order == ADD)
            program_str += "ADD";
        else if(program[i].order == SUB)
            program_str += "SUB";
        else if(program[i].order == MOV)
            program_str += "MOV";
        else if(program[i].order == INT_00H)
            program_str += "INT 00H";
        else if(program[i].order == INT_2AH)
            program_str += "INT 2AH";
        else if(program[i].order == INT_2CH)
            program_str += "INT 2CH";
        else if(program[i].order == PUSH)
            program_str += "PUSH";
        else if(program[i].order == POP)
            program_str += "POP";
        else if(program[i].order == INT_0DH)
            program_str += "INT 0DH";
        else if(program[i].order == INT_41H)
            program_str += "INT 41H";
        else if(program[i].order == INT_47H)
            program_str += "INT 47H";
        else if(program[i].order == INT_56H)
            program_str += "INT 56H";
        else if(program[i].order == INT_48H)
            program_str += "INT 48H";
        else if(program[i].order == INT_49H)
            program_str += "INT 49H";
        else if(program[i].order == INT_4AH)
            program_str += "INT 4AH";
        else
            program_str += "???";
        program_str += " ";


        if(program[i].first == "A")
            program_str += "A";
        else if(program[i].first == "B")
            program_str += "B";
        else if(program[i].first == "C")
            program_str += "C";
        else if(program[i].first == "D")
            program_str += "D";
        else if(program[i].first == "_")
            program_str += "_";
        else
            program_str += "?";
        program_str += " ";


        if(program[i].second == "A")
            program_str += "A";
        else if(program[i].second == "B")
            program_str += "B";
        else if(program[i].second == "C")
            program_str += "C";
        else if(program[i].second == "D")
            program_str += "D";
//            else if(program[i].second == "INPUT"){
//                std::string input = input_h + input_l;
//                program_str += input;
//            }
        else    // INPUT - program[i].second nigdy nie będzie = "INPUT" bo program[i].second = np. "0010000100101100"
            program_str += program[i].second;
        program_str += " ";



        if(program[i].third == "A")
            program_str += "A";
        else if(program[i].third == "B")
            program_str += "B";
        else if(program[i].third == "C")
            program_str += "C";
        else if(program[i].third == "D")
            program_str += "D";
        else
            program_str += "_";

        program_str += "\n";
    }

    // ----------- wyświetlanie aktualnych orderów (programu) w labelu po prawej
    ui->label_program->setText(QString::fromStdString(program_str));
}


void MainWindow::display_order_numbers(int numer_aktualnego_rozkazu = -1){
    // --------------------------------- wypisywanie numerów rozkazów w programie
    std::string numerki = "";
    for(int i = 0; i<how_many_orders; i++){
        if(i == numer_aktualnego_rozkazu){
            numerki += "=" + std::to_string(i) + "=";
        }else{
            numerki += std::to_string(i);
        }
        numerki += "\n";
    }
    // -------------------------------- wyświetlanie
    ui->label_program_number->setText(QString::fromStdString(numerki));
}


void MainWindow::on_save_order_button_clicked()
{
    how_many_orders++;
    if(how_many_orders > NUMBER_OF_ORDERS_IN_PROGRAM){
        ui->label_order_limit_reached->setGeometry(480, 590, 281, 21);
        how_many_orders--;
    }else{
        // ----------- resetowanie komunikatów błedów
        ui->label_result_less_than_zero->setGeometry(680, 330, 121, 1);
        ui->label_order_limit_reached->setGeometry(480, 590, 281, 1);

        // ------------- zapisywanie ordera do tablicy orderów (programu)
        if(ui->combo_box_order->currentText() == "MOV")
            program[how_many_orders-1].order = MOV;
        else if(ui->combo_box_order->currentText() == "ADD")
            program[how_many_orders-1].order = ADD;
        else if(ui->combo_box_order->currentText() == "SUB")
            program[how_many_orders-1].order = SUB;
        else if(ui->combo_box_order->currentText() == "INT 00H")
            program[how_many_orders-1].order = INT_00H;
        else if(ui->combo_box_order->currentText() == "INT 2AH")
            program[how_many_orders-1].order = INT_2AH;
        else if(ui->combo_box_order->currentText() == "INT 2CH")
            program[how_many_orders-1].order = INT_2CH;
        else if(ui->combo_box_order->currentText() == "PUSH")
            program[how_many_orders-1].order = PUSH;
        else if(ui->combo_box_order->currentText() == "POP")
            program[how_many_orders-1].order = POP;
        else if(ui->combo_box_order->currentText() == "INT 0DH")
            program[how_many_orders-1].order = INT_0DH;
        else if(ui->combo_box_order->currentText() == "INT 41H")
            program[how_many_orders-1].order = INT_41H;
        else if(ui->combo_box_order->currentText() == "INT 47H")
            program[how_many_orders-1].order = INT_47H;
        else if(ui->combo_box_order->currentText() == "INT 56H")
            program[how_many_orders-1].order = INT_56H;
        else if(ui->combo_box_order->currentText() == "INT 48H")
            program[how_many_orders-1].order = INT_48H;
        else if(ui->combo_box_order->currentText() == "INT 49H")
            program[how_many_orders-1].order = INT_49H;
        else if(ui->combo_box_order->currentText() == "INT 4AH")
            program[how_many_orders-1].order = INT_4AH;


        if(ui->combo_box_order->currentText() == "INT 2CH" ||
                ui->combo_box_order->currentText() == "INT 2AH" ||
                ui->combo_box_order->currentText() == "INT 00H" ||
                ui->combo_box_order->currentText() == "INT 0DH" ||
                ui->combo_box_order->currentText() == "INT 41H" ||
                ui->combo_box_order->currentText() == "INT 47H" ||
                ui->combo_box_order->currentText() == "INT 56H" ||
                ui->combo_box_order->currentText() == "INT 49H"){

            program[how_many_orders-1].first = "_";
            program[how_many_orders-1].second = "_";
            program[how_many_orders-1].third = "_";

        }else if(ui->combo_box_order->currentText() == "POP" || ui->combo_box_order->currentText() == "PUSH"
                  || ui->combo_box_order->currentText() == "INT 48H" || ui->combo_box_order->currentText() == "INT 4AH"){

            if(ui->combo_box_one->currentText() == "A"){
                program[how_many_orders-1].first = "A";
            }
            else if(ui->combo_box_one->currentText() == "B"){
                program[how_many_orders-1].first = "B";
            }
            else if(ui->combo_box_one->currentText() == "C"){
                program[how_many_orders-1].first = "C";
            }
            else if(ui->combo_box_one->currentText() == "D"){
                program[how_many_orders-1].first = "D";
            }

            program[how_many_orders-1].second = "_";
            program[how_many_orders-1].third = "_";

        }else{

            if(ui->combo_box_two->currentText() == "INPUT"){    // tryb natychmiastowy adresowania

                program[how_many_orders-1].second = input_h + input_l;
                std::cout << "program[" << how_many_orders-1 << "].second = (input) " << input_h << input_l << "\n";

                if(ui->combo_box_one->currentText() == "A"){

                    program[how_many_orders-1].first = "A";
                    program[how_many_orders-1].third = "_";
                    /*
                    program[how_many_orders-1].first = register_ah + register_al;
                    program[how_many_orders-1].third = "_";
                    */
                }
                else if(ui->combo_box_one->currentText() == "B"){

                    program[how_many_orders-1].first = "B";
                    program[how_many_orders-1].third = "_";
                }
                else if(ui->combo_box_one->currentText() == "C"){

                    program[how_many_orders-1].first = "C";
                    program[how_many_orders-1].third = "_";
                }
                else if(ui->combo_box_one->currentText() == "D"){

                    program[how_many_orders-1].first = "D";
                    program[how_many_orders-1].third = "_";
                }

            }else{ // -------------------------------------------- tryb rejestrowy adresowania

                if(ui->combo_box_one->currentText() == "A"){

                    program[how_many_orders-1].first = "A";
                    // program[how_many_orders-1].first = register_ah + register_al;
                }
                else if(ui->combo_box_one->currentText() == "B"){
                    program[how_many_orders-1].first = "B";
                }
                else if(ui->combo_box_one->currentText() == "C"){
                    program[how_many_orders-1].first = "C";
                }
                else if(ui->combo_box_one->currentText() == "D"){
                    program[how_many_orders-1].first = "D";
                }

                if(ui->combo_box_two->currentText() == "A"){
                    program[how_many_orders-1].second = "A";
                }
                else if(ui->combo_box_two->currentText() == "B"){
                    program[how_many_orders-1].second = "B";
                }
                else if(ui->combo_box_two->currentText() == "C"){
                    program[how_many_orders-1].second = "C";
                }
                else if(ui->combo_box_two->currentText() == "D"){
                    program[how_many_orders-1].second = "D";
                }

                if(ui->combo_box_order->currentText() == "MOV")
                    program[how_many_orders-1].third = "_";
                else{
                    if(ui->combo_box_three->currentText() == "A"){
                        program[how_many_orders-1].third = "A";
                    }
                    else if(ui->combo_box_three->currentText() == "B"){
                        program[how_many_orders-1].third = "B";
                    }
                    else if(ui->combo_box_three->currentText() == "C"){
                        program[how_many_orders-1].third = "C";
                    }
                    else if(ui->combo_box_three->currentText() == "D"){
                        program[how_many_orders-1].third = "D";
                    }
                }
            }
        }

        // ----------- wyś◘wietlam aktualny program
        display_program();
        display_order_numbers();
    }
}

void MainWindow::on_save_program_button_clicked()
{
    // QString filename = QString::fromStdString(program_file_name);
    // directory = getcwd()
    // directory append(filename)

    // zapisanie stringa program_str w pliku
    // QString filename = "D:\\PROJEKTY\\Qt_PROJECTS\\Microprocessor-simulation-ASK-1-project-\\my_program.txt";
    QString filename = QString::fromStdString(program_file_name);
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&file);
        stream << QString::fromStdString(program_str) << endl;
    }
    file.close();
}

void MainWindow::on_load_program_button_clicked()
{
    // QString filename = "D:\\PROJEKTY\\Qt_PROJECTS\\Microprocessor-simulation-ASK-1-project-\\my_program.txt";
    QString filename = QString::fromStdString(program_file_name);
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    ui->label_program->setText("");
    how_many_orders = 0;

    while(!in.atEnd()) {
        QString line = in.readLine();
        std::string line_str = line.toStdString();

        if(line_str.substr(0,7) == "INT 00H" || line_str.substr(0,7) == "INT 2AH" || line_str.substr(0,7) == "INT 2CH"
                || line_str.substr(0,7) == "INT 0DH" || line_str.substr(0,7) == "INT 41H" || line_str.substr(0,7) == "INT 47H"
                 || line_str.substr(0,7) == "INT 56H" || line_str.substr(0,7) == "INT 49H" || line_str.substr(0,7) == "INT 48H"
                 || line_str.substr(0,7) == "INT 4AH"){

            if(line_str.substr(0,7) == "INT 00H")
                program[how_many_orders].order = INT_00H;
            else if(line_str.substr(0,7) == "INT 2AH")
                program[how_many_orders].order = INT_2AH;
            else if(line_str.substr(0,7) == "INT 2CH")
                program[how_many_orders].order = INT_2CH;
            else if(line_str.substr(0,7) == "INT 0DH")
                program[how_many_orders].order = INT_0DH;
            else if(line_str.substr(0,7) == "INT 41H")
                program[how_many_orders].order = INT_41H;
            else if(line_str.substr(0,7) == "INT 47H")
                program[how_many_orders].order = INT_47H;
            else if(line_str.substr(0,7) == "INT 56H")
                program[how_many_orders].order = INT_56H;
            else if(line_str.substr(0,7) == "INT 49H")
                program[how_many_orders].order = INT_49H;

            program[how_many_orders].first = "_";
            program[how_many_orders].second = "_";
            program[how_many_orders].third = "_";


            if(line_str.substr(0,7) == "INT 48H"){
                program[how_many_orders].order = INT_48H;
                if(line_str[7] == 'A')
                    program[how_many_orders].first = "A";
                else if(line_str[7] == 'B')
                    program[how_many_orders].first = "B";
                else if(line_str[7] == 'C')
                    program[how_many_orders].first = "C";
                else if(line_str[7] == 'D')
                    program[how_many_orders].first = "D";

            }else if(line_str.substr(0,7) == "INT 4AH"){
                program[how_many_orders].order = INT_4AH;
                if(line_str[7] == 'A')
                    program[how_many_orders].first = "A";
                else if(line_str[7] == 'B')
                    program[how_many_orders].first = "B";
                else if(line_str[7] == 'C')
                    program[how_many_orders].first = "C";
                else if(line_str[7] == 'D')
                    program[how_many_orders].first = "D";

            }

        }else if(line_str.substr(0,4) == "PUSH"){

            program[how_many_orders].order = PUSH;

            if(line_str[5] == 'A')
                program[how_many_orders].first = "A";
            else if(line_str[5] == 'B')
                program[how_many_orders].first = "B";
            else if(line_str[5] == 'C')
                program[how_many_orders].first = "C";
            else if(line_str[5] == 'D')
                program[how_many_orders].first = "D";

            program[how_many_orders].second = "_";
            program[how_many_orders].third = "_";

        }else{

            if(line_str.substr(0,3) == "MOV")
                program[how_many_orders].order = MOV;
            else if(line_str.substr(0,3) == "ADD")
                program[how_many_orders].order = ADD;
            else if(line_str.substr(0,3) == "SUB")
                program[how_many_orders].order = SUB;
            else if(line_str.substr(0,3) == "POP")
                program[how_many_orders].order = POP;

            if(line_str[4] == 'A')
                program[how_many_orders].first = "A";
            else if(line_str[4] == 'B')
                program[how_many_orders].first = "B";
            else if(line_str[4] == 'C')
                program[how_many_orders].first = "C";
            else if(line_str[4] == 'D')
                program[how_many_orders].first = "D";

            if(line_str[6] == '0' || line_str[6] == '1'){
                program[how_many_orders].second = line_str.substr(6,16);
                program[how_many_orders].third = "_";
            }else{
                program[how_many_orders].second = line_str[6];
                program[how_many_orders].third = line_str[8];
            }
        }

        std::cout << line_str << "\n";

        how_many_orders++;
    }
    how_many_orders--;

    // ----------- wyś◘wietlam aktualny program
    display_program();
    display_order_numbers();
    //how_many_orders--;
    file.close();
}

void MainWindow::on_perform_step_button_clicked()
{
    display_order_numbers(order_number);

    if(program[order_number].order == MOV){ // --------------------------------- MOV
        std::string from_h, from_l;

        if(program[order_number].first == "A"){
            from_h = register_ah;
            from_l = register_al;
        }else if(program[order_number].first == "B"){
            from_h = register_bh;
            from_l = register_bl;
        }else if(program[order_number].first == "C"){
            from_h = register_ch;
            from_l = register_cl;
        }else if(program[order_number].first == "D"){
            from_h = register_dh;
            from_l = register_dl;
        }

        if(program[order_number].second == "A"){
            register_ah = from_h;
            register_al = from_l;
            ui->a_register_l->setText(QString::fromStdString(register_al));
            ui->a_register_h->setText(QString::fromStdString(register_ah));
        }else if(program[order_number].second == "B"){
            register_bh = from_h;
            register_bl = from_l;
            ui->b_register_l->setText(QString::fromStdString(register_bl));
            ui->b_register_h->setText(QString::fromStdString(register_bh));
        }else if(program[order_number].second == "C"){
            register_ch = from_h;
            register_cl = from_l;
            ui->c_register_l->setText(QString::fromStdString(register_cl));
            ui->c_register_h->setText(QString::fromStdString(register_ch));
        }else if(program[order_number].second == "D"){
            register_dh = from_h;
            register_dl = from_l;
            ui->d_register_l->setText(QString::fromStdString(register_dl));
            ui->d_register_h->setText(QString::fromStdString(register_dh));

        }else{  // INPUT (np. 1000111100001010)
            if(program[order_number].first == "A"){
                register_ah = program[order_number].second.substr(0,8);
                register_al = program[order_number].second.substr(8,8);
                ui->a_register_l->setText(QString::fromStdString(register_al));
                ui->a_register_h->setText(QString::fromStdString(register_ah));
            }else if(program[order_number].first == "B"){
                register_bh = program[order_number].second.substr(0,8);
                register_bl = program[order_number].second.substr(8,8);
                ui->b_register_l->setText(QString::fromStdString(register_bl));
                ui->b_register_h->setText(QString::fromStdString(register_bh));
            }else if(program[order_number].first == "C"){
                register_ch = program[order_number].second.substr(0,8);
                register_cl = program[order_number].second.substr(8,8);
                ui->c_register_l->setText(QString::fromStdString(register_cl));
                ui->c_register_h->setText(QString::fromStdString(register_ch));
            }else if(program[order_number].first == "D"){
                register_dh = program[order_number].second.substr(0,8);
                register_dl = program[order_number].second.substr(8,8);
                ui->d_register_l->setText(QString::fromStdString(register_dl));
                ui->d_register_h->setText(QString::fromStdString(register_dh));
            }
        }
    }else if(program[order_number].order == ADD){// --------------------------------- ADD

        std::string first, second, answer;

        if(program[order_number].first == "A"){
            first = register_ah + register_al;
        }else if(program[order_number].first == "B"){
            first = register_bh + register_bl;
        }else if(program[order_number].first == "C"){
            first = register_ch + register_cl;
        }else if(program[order_number].first == "D"){
            first = register_dh + register_dl;
        }

        if(program[order_number].second == "A"){
            second = register_ah + register_al;
        }else if(program[order_number].second == "B"){
            second = register_bh + register_bl;
        }else if(program[order_number].second == "C"){
            second = register_ch + register_cl;
        }else if(program[order_number].second == "D"){
            second = register_dh + register_dl;
        }else{                                      // =============== INPUT - tryb adresowania natychmiastowego

            second = program[order_number].second;
            answer = addBinary(first, second);

            if(program[order_number].first == "A"){
                register_ah = "";
                register_al = "";
                if(answer.size() == 16){
                    for(int i = 0; i < 8; i++)
                        register_ah = register_ah + answer[i];
                    for(int i = 8; i < 16; i++)
                        register_al = register_al + answer[i];
                }else if(answer.size() == 17){  // w przypadku przepełnienia tracimy 'wystającą' poza rejestr jedynkę
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

            }else if(program[order_number].first == "B"){
                register_bh = "";
                register_bl = "";
                if(answer.size() == 16){
                    for(int i = 0; i < 8; i++)
                        register_bh = register_bh + answer[i];
                    for(int i = 8; i < 16; i++)
                        register_bl = register_bl + answer[i];
                }else if(answer.size() == 17){  // w przypadku przepełnienia tracimy 'wystającą' poza rejestr jedynkę
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

            }else if(program[order_number].first == "C"){
                register_ch = "";
                register_cl = "";
                if(answer.size() == 16){
                    for(int i = 0; i < 8; i++)
                        register_ch = register_ch + answer[i];
                    for(int i = 8; i < 16; i++)
                        register_cl = register_cl + answer[i];
                }else if(answer.size() == 17){  // w przypadku przepełnienia tracimy 'wystającą' poza rejestr jedynkę
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

            }else if(program[order_number].first == "D"){

                register_dh = "";
                register_dl = "";
                if(answer.size() == 16){
                    for(int i = 0; i < 8; i++)
                        register_dh = register_dh + answer[i];
                    for(int i = 8; i < 16; i++)
                        register_dl = register_dl + answer[i];
                }else if(answer.size() == 17){  // w przypadku przepełnienia tracimy 'wystającą' poza rejestr jedynkę
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
            }
        }

        answer = addBinary(first, second);
        if(program[order_number].third == "A"){
            register_ah = "";
            register_al = "";
            if(answer.size() == 16){
                for(int i = 0; i < 8; i++)
                    register_ah = register_ah + answer[i];
                for(int i = 8; i < 16; i++)
                    register_al = register_al + answer[i];
            }else if(answer.size() == 17){  // w przypadku przepełnienia tracimy 'wystającą' poza rejestr jedynkę
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
        }else if(program[order_number].third == "B"){
            register_bh = "";
            register_bl = "";
            if(answer.size() == 16){
                for(int i = 0; i < 8; i++)
                    register_bh = register_bh + answer[i];
                for(int i = 8; i < 16; i++)
                    register_bl = register_bl + answer[i];
            }else if(answer.size() == 17){  // w przypadku przepełnienia tracimy 'wystającą' poza rejestr jedynkę
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
        }else if(program[order_number].third == "C"){
            register_ch = "";
            register_cl = "";
            if(answer.size() == 16){
                for(int i = 0; i < 8; i++)
                    register_ch = register_ch + answer[i];
                for(int i = 8; i < 16; i++)
                    register_cl = register_cl + answer[i];
            }else if(answer.size() == 17){  // w przypadku przepełnienia tracimy 'wystającą' poza rejestr jedynkę
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
        }else if(program[order_number].third == "D"){
            register_dh = "";
            register_dl = "";
            if(answer.size() == 16){
                for(int i = 0; i < 8; i++)
                    register_dh = register_dh + answer[i];
                for(int i = 8; i < 16; i++)
                    register_dl = register_dl + answer[i];
            }else if(answer.size() == 17){  // w przypadku przepełnienia tracimy 'wystającą' poza rejestr jedynkę
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
            //INPUT
        }

    }else if(program[order_number].order == SUB){// --------------------------------- SUB
        std::string first, second, answer;

        if(program[order_number].first == "A"){
            first = register_ah + register_al;
        }else if(program[order_number].first == "B"){
            first = register_bh + register_bl;
        }else if(program[order_number].first == "C"){
            first = register_ch + register_cl;
        }else if(program[order_number].first == "D"){
            first = register_dh + register_dl;
        }else{
            std::cout << "ERROR: pobieranie pierwszego rejestru z zapisanego programu\n";
            // ui->combo_box_one->setCurrentText("ERROR");
        }

        if(program[order_number].second == "A"){
            second = register_ah + register_al;
        }else if(program[order_number].second == "B"){
            second = register_bh + register_bl;
        }else if(program[order_number].second == "C"){
            second = register_ch + register_cl;
        }else if(program[order_number].second == "D"){
            second = register_dh + register_dl;
        }else{                                      // INPUT

            second = program[order_number].second;

            int first_int = binary_to_int(first);
            int second_int = binary_to_int(second);

            if(first_int < second_int){
                ui->label_result_less_than_zero->setGeometry(680, 330, 121, 71);
            }

            int answer_int = first_int - second_int;
            answer = decimal_to_binary(answer_int);

            if(program[order_number].first == "A"){

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

            }else if(program[order_number].first == "B"){

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

            }else if(program[order_number].first == "C"){

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

            }else if(program[order_number].first == "D"){

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

            }

        }

        if(program[order_number].second == "A" || program[order_number].second == "B" || program[order_number].second == "C" || program[order_number].second == "D"){
            if(program[order_number].third == "A"){
                // std::cout << "\n\nfirst: " << first;
                // std::cout << "\nsecond: " << first;

                // int binary_to_int(std::string input)
                int first_int = binary_to_int(first);
                int second_int = binary_to_int(second);
                // std::cout << "\nfirst_int: " << first_int;
                // std::cout << "\nsecond_int: " << second_int;

                if(first_int < second_int){
                    ui->label_result_less_than_zero->setGeometry(680, 330, 121, 71);
                }

                // odejmowanie intów
                int answer_int = first_int - second_int;
                // std::cout << "\nanswer_int: " << answer_int;

                answer = decimal_to_binary(answer_int);
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

            }else if(program[order_number].third == "B"){
                int first_int = binary_to_int(first);
                int second_int = binary_to_int(second);

                if(first_int < second_int){
                    ui->label_result_less_than_zero->setGeometry(680, 330, 121, 71);
                }

                int answer_int = first_int - second_int;
                answer = decimal_to_binary(answer_int);


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

            }else if(program[order_number].third == "C"){
                int first_int = binary_to_int(first);
                int second_int = binary_to_int(second);

                if(first_int < second_int){
                    ui->label_result_less_than_zero->setGeometry(680, 330, 121, 71);
                }

                int answer_int = first_int - second_int;
                answer = decimal_to_binary(answer_int);


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

            }else if(program[order_number].third == "D"){

                int first_int = binary_to_int(first);
                int second_int = binary_to_int(second);

                if(first_int < second_int){
                    ui->label_result_less_than_zero->setGeometry(680, 330, 121, 71);
                }

                int answer_int = first_int - second_int;
                answer = decimal_to_binary(answer_int);


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
            }
        }
    }else if(program[order_number].order == INT_00H){

        QCoreApplication::quit();

    }else if(program[order_number].order == INT_2CH){   // ===================================================== POBIERZ CZAS

        // current date/time based on current system
        time_t now = time(NULL);
        tm *ltm = localtime(&now);

        int hour    = ltm->tm_hour;
        int minute  = ltm->tm_min;
        int second  = ltm->tm_sec;

        register_ch = "";
        register_cl = "";
        register_dh = "";

        std::string time_str = decimal_to_binary(hour);

        for(int i = 8; i < 16; i++)
            register_ch = register_ch + time_str[i];
        ui->c_register_h->setText(QString::fromStdString(register_ch));

        time_str = decimal_to_binary(minute);
        for(int i = 8; i < 16; i++)
            register_cl = register_cl + time_str[i];
        ui->c_register_l->setText(QString::fromStdString(register_cl));

        time_str = decimal_to_binary(second);
        for(int i = 8; i < 16; i++)
            register_dh = register_dh + time_str[i];
        ui->d_register_h->setText(QString::fromStdString(register_dh));


    }else if(program[order_number].order == INT_2AH){   // ===================================================== POBIERZ DATĘ

        // current date/time based on current system
        time_t now = time(NULL);
        tm *ltm = localtime(&now);

        int year    = 1900 + ltm->tm_year;
        int month   = 1 + ltm->tm_mon;
        int day     = ltm->tm_mday;

        std::string data_str = decimal_to_binary(year);
        register_ch = "";
        register_cl = "";
        for(int i = 0; i < 8; i++)
            register_ch = register_ch + data_str[i];
        for(int i = 8; i < 16; i++)
            register_cl = register_cl + data_str[i];
        ui->c_register_l->setText(QString::fromStdString(register_cl));
        ui->c_register_h->setText(QString::fromStdString(register_ch));

        data_str = decimal_to_binary(month);
        register_dh = "";
        register_dl = "";
        for(int i = 8; i < 16; i++)
            register_dh = register_dh + data_str[i];
        ui->d_register_h->setText(QString::fromStdString(register_dh));

        data_str = decimal_to_binary(day);
        for(int i = 8; i < 16; i++)
            register_dl = register_dl + data_str[i];
        ui->d_register_l->setText(QString::fromStdString(register_dl));

    }else if(program[order_number].order == PUSH){     // ===================================================== WSTAW NA STOS

        std::string push_str;

        if(program[order_number].first == "A"){
            push_str = register_ah + register_al;
        }else if(program[order_number].first == "B"){
            push_str = register_bh + register_bl;
        }else if(program[order_number].first == "C"){
            push_str = register_ch + register_cl;
        }else if(program[order_number].first == "D"){
            push_str = register_dh + register_dl;
        }else{
            std::cout << "ERROR: pobieranie rejestru z zapisanego programu do PUSH\n";
        }

        int push_int = binary_to_int(push_str);
        stack[stack_ptr] = push_int;
        stack_ptr--;

    }else if(program[order_number].order == POP){   // ===================================================== ZDEJMIJ ZE STOSU

        stack_ptr++;
        int pop_int = stack[stack_ptr];
        std::string pop_str = decimal_to_binary(pop_int);

        if(program[order_number].first == "A"){

            register_ah = "";
            register_al = "";
            if(pop_str.size() == 16){
                for(int i = 0; i < 8; i++)
                    register_ah = register_ah + pop_str[i];
                for(int i = 8; i < 16; i++)
                    register_al = register_al + pop_str[i];
            }else if(pop_str.size() == 17){  // ============================ w przypadku przepełnienia tracimy 'wystającą' poza rejestr jedynkę
                for(int i = 1; i < 9; i++)
                    register_ah = register_ah + pop_str[i];
                for(int i = 9; i < 17; i++)
                    register_al = register_al + pop_str[i];
            }else{
                register_ah = "ERROR";
                register_al = "ERROR";
            }
            ui->a_register_l->setText(QString::fromStdString(register_al));
            ui->a_register_h->setText(QString::fromStdString(register_ah));

        }else if(program[order_number].first == "B"){

            register_bh = "";
            register_bl = "";
            if(pop_str.size() == 16){
                for(int i = 0; i < 8; i++)
                    register_bh = register_bh + pop_str[i];
                for(int i = 8; i < 16; i++)
                    register_bl = register_bl + pop_str[i];
            }else if(pop_str.size() == 17){  // ============================ w przypadku przepełnienia tracimy 'wystającą' poza rejestr jedynkę
                for(int i = 1; i < 9; i++)
                    register_bh = register_bh + pop_str[i];
                for(int i = 9; i < 17; i++)
                    register_bl = register_bl + pop_str[i];
            }else{
                register_bh = "ERROR";
                register_bl = "ERROR";
            }
            ui->b_register_l->setText(QString::fromStdString(register_bl));
            ui->b_register_h->setText(QString::fromStdString(register_bh));

        }else if(program[order_number].first == "C"){

            register_ch = "";
            register_cl = "";
            if(pop_str.size() == 16){
                for(int i = 0; i < 8; i++)
                    register_ch = register_ch + pop_str[i];
                for(int i = 8; i < 16; i++)
                    register_cl = register_cl + pop_str[i];
            }else if(pop_str.size() == 17){  // ============================ w przypadku przepełnienia tracimy 'wystającą' poza rejestr jedynkę
                for(int i = 1; i < 9; i++)
                    register_ch = register_ch + pop_str[i];
                for(int i = 9; i < 17; i++)
                    register_cl = register_cl + pop_str[i];
            }else{
                register_ch = "ERROR";
                register_cl = "ERROR";
            }
            ui->c_register_l->setText(QString::fromStdString(register_cl));
            ui->c_register_h->setText(QString::fromStdString(register_ch));

        }else if(program[order_number].first == "D"){

            register_dh = "";
            register_dl = "";
            if(pop_str.size() == 16){
                for(int i = 0; i < 8; i++)
                    register_dh = register_dh + pop_str[i];
                for(int i = 8; i < 16; i++)
                    register_dl = register_dl + pop_str[i];
            }else if(pop_str.size() == 17){  // ============================ w przypadku przepełnienia tracimy 'wystającą' poza rejestr jedynkę
                for(int i = 1; i < 9; i++)
                    register_dh = register_dh + pop_str[i];
                for(int i = 9; i < 17; i++)
                    register_dl = register_dl + pop_str[i];
            }else{
                register_dh = "ERROR";
                register_dl = "ERROR";
            }
            ui->d_register_l->setText(QString::fromStdString(register_dl));
            ui->d_register_h->setText(QString::fromStdString(register_dh));

        }else{
            std::cout << "ERROR: pobieranie rejestru z zapisanego programu do POP\n";
        }

    }else if(program[order_number].order == INT_0DH){   // ===================================================== RESET DYSKU
        // zeruj rejestry i program

        // kasuj zawartość pliku z programem
        std::ofstream ofs;
        ofs.open(program_file_name, std::ofstream::out | std::ofstream::trunc);
        ofs.close();

        // zeruj zawartośc rejestrów
        register_al = "00000000";
        register_ah = "00000000";
        ui->a_register_l->setText(QString::fromStdString(register_al));
        ui->a_register_h->setText(QString::fromStdString(register_ah));

        register_cl = "00000000";
        register_ch = "00000000";
        ui->c_register_l->setText(QString::fromStdString(register_cl));
        ui->c_register_h->setText(QString::fromStdString(register_ch));

        register_bl = "00000000";
        register_bh = "00000000";
        ui->b_register_l->setText(QString::fromStdString(register_bl));
        ui->b_register_h->setText(QString::fromStdString(register_bh));

        register_dl = "00000000";
        register_dh = "00000000";
        ui->d_register_l->setText(QString::fromStdString(register_dl));
        ui->d_register_h->setText(QString::fromStdString(register_dh));

    }else if(program[order_number].order == INT_41H){   // ===================================================== KASUJ PLIK (plik programu)
        // remove("filename.txt")
        const char *filename = program_file_name.c_str();

        std::remove(filename);

    }else if(program[order_number].order == INT_47H){   // ===================================================== POBIERZ AKTUALNY KATALOG / DIRECTORY
        get_current_dir("show");

    }else if(program[order_number].order == INT_56H){   // ===================================================== ZMIEŃu NAZWĘ PLIKU (plik programu)
        bool ok;
        QString text = QInputDialog::getText(this, tr("Okno nowej nazwy pliku programu"),
                                                 tr("nowa nazwa pliku programu:"), QLineEdit::Normal,
                                                 QDir::home().dirName(), &ok);

        if (ok && !text.isEmpty()){
            if(text.contains(".txt", Qt::CaseSensitive)){
                // text kończy się ".txt" to nie dokładaj ".txt"
            }else{
                // dodaj ".txt" na końcu nowej nazwy pliku otrzymanej od użytkownika
                text = text + ".txt";
            }

            //konwersja z std::string lub Qstring na const char*
            const char *c_old_name = program_file_name.c_str();

            QByteArray ba = text.toLocal8Bit();
            const char *c_new_name = ba.data();

            std::rename(c_old_name, c_new_name);
            program_file_name = text.toStdString();
        }

    }else if(program[order_number].order == INT_48H){   // ===================================================== ALOKUJ BLOK PAMIĘCI

        if(program[order_number].first == "A"){
            memory_blocks.push_front(register_ah + register_al);
        }else if(program[order_number].first == "B"){
            memory_blocks.push_front(register_bh + register_bl);
        }else if(program[order_number].first == "C"){
            memory_blocks.push_front(register_ch + register_cl);
        }else if(program[order_number].first == "D"){
            memory_blocks.push_front(register_dh + register_dl);
        }else{
            std::cout << "ERROR INT 48H: Nie udalo sie utworzyc nowego bloku pamieci\n";
        }


    }else if(program[order_number].order == INT_49H){   // ===================================================== ZWOLNIJ ZAALOKOWANĄ PAMIĘĆ
        // <list> clear()
        memory_blocks.clear();


    }else if(program[order_number].order == INT_4AH){   // ===================================================== MODYFIKUJ ZAALOKOWANĄ PAMIĘĆ

        uint8_t counter = 0;    // max 256

        while(memory_blocks.empty() == false){
            counter++;
            memory_blocks.pop_back();
        }

        for(uint8_t i = 0; i < counter; i++){

            if(program[order_number].first == "A"){
                memory_blocks.push_front(register_ah + register_al);
            }else if(program[order_number].first == "B"){
                memory_blocks.push_front(register_bh + register_bl);
            }else if(program[order_number].first == "C"){
                memory_blocks.push_front(register_ch + register_cl);
            }else if(program[order_number].first == "D"){
                memory_blocks.push_front(register_dh + register_dl);
            }else{
                std::cout << "ERROR INT 4AH: Nie udalo sie wstawic zamiennego bloku pamieci\n";
            }

        }

    }else{
        std::cout << "ERROR: nieudane rozpoznanie\nrozkazu przy on_perform_step_button_clicked()\n";
    }

    order_number++;
    if(order_number>how_many_orders)
        order_number = 0;

}

void MainWindow::on_perform_program_button_clicked(){    // wykonaj cały program
    order_number = 0;
    for(int i = 0; i <= how_many_orders; i++){

        on_perform_step_button_clicked();

    }
}
