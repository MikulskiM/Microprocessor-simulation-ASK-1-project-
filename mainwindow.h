#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "order.h"
#include <ctime>    // znajdowanie daty i czasu dla przerwań
#include <stdio.h>  // sprintf()


#define NUMBER_OF_ORDERS_IN_PROGRAM 8   // maxymalna liczba rozkazów przypadająca na pojedynczy program
#define STACK_SIZE  32


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // ---- my data
    std::string register_input_ah = "00000000";
    std::string register_input_al = "00000000";
    std::string register_input_bh = "00000000";
    std::string register_input_bl = "00000000";
    std::string register_input_ch = "00000000";
    std::string register_input_cl = "00000000";
    std::string register_input_dh = "00000000";
    std::string register_input_dl = "00000000";

    std::string register_ah = "00000000";
    std::string register_al = "00000000";
    std::string register_bh = "00000000";
    std::string register_bl = "00000000";
    std::string register_ch = "00000000";
    std::string register_cl = "00000000";
    std::string register_dh = "00000000";
    std::string register_dl = "00000000";

    std::string input_h = "00000000";
    std::string input_l = "00000000";

    int how_many_orders = 0;
    Order program[NUMBER_OF_ORDERS_IN_PROGRAM];

    std::string program_str = "";

    int order_number = 0;

    short stack[STACK_SIZE];
    int stack_ptr = STACK_SIZE - 1;

    // ----

private slots:

    void on_radioButton_a1_15_clicked();
    void on_radioButton_a1_14_clicked();
    void on_radioButton_a1_13_clicked();
    void on_radioButton_a1_12_clicked();
    void on_radioButton_a1_11_clicked();
    void on_radioButton_a1_10_clicked();
    void on_radioButton_a1_9_clicked();
    void on_radioButton_a1_8_clicked();
    void on_radioButton_a1_7_clicked();
    void on_radioButton_a1_6_clicked();
    void on_radioButton_a1_5_clicked();
    void on_radioButton_a1_4_clicked();
    void on_radioButton_a1_3_clicked();
    void on_radioButton_a1_2_clicked();
    void on_radioButton_a1_1_clicked();
    void on_radioButton_a1_0_clicked();

    void on_radioButton_a0_0_clicked();
    void on_radioButton_a0_1_clicked();
    void on_radioButton_a0_2_clicked();
    void on_radioButton_a0_3_clicked();
    void on_radioButton_a0_4_clicked();
    void on_radioButton_a0_5_clicked();
    void on_radioButton_a0_6_clicked();
    void on_radioButton_a0_7_clicked();
    void on_radioButton_a0_8_clicked();
    void on_radioButton_a0_9_clicked();
    void on_radioButton_a0_10_clicked();
    void on_radioButton_a0_11_clicked();
    void on_radioButton_a0_12_clicked();
    void on_radioButton_a0_13_clicked();
    void on_radioButton_a0_14_clicked();
    void on_radioButton_a0_15_clicked();

    void on_radioButton_b1_15_clicked();
    void on_radioButton_b1_0_clicked();
    void on_radioButton_b1_1_clicked();
    void on_radioButton_b1_2_clicked();
    void on_radioButton_b1_3_clicked();
    void on_radioButton_b1_4_clicked();
    void on_radioButton_b1_5_clicked();
    void on_radioButton_b1_6_clicked();
    void on_radioButton_b1_7_clicked();
    void on_radioButton_b1_8_clicked();
    void on_radioButton_b1_9_clicked();
    void on_radioButton_b1_10_clicked();
    void on_radioButton_b1_11_clicked();
    void on_radioButton_b1_12_clicked();
    void on_radioButton_b1_13_clicked();
    void on_radioButton_b1_14_clicked();

    void on_radioButton_b0_0_clicked();
    void on_radioButton_b0_1_clicked();
    void on_radioButton_b0_2_clicked();
    void on_radioButton_b0_3_clicked();
    void on_radioButton_b0_4_clicked();
    void on_radioButton_b0_5_clicked();
    void on_radioButton_b0_6_clicked();
    void on_radioButton_b0_7_clicked();
    void on_radioButton_b0_8_clicked();
    void on_radioButton_b0_9_clicked();
    void on_radioButton_b0_10_clicked();
    void on_radioButton_b0_11_clicked();
    void on_radioButton_b0_12_clicked();
    void on_radioButton_b0_13_clicked();
    void on_radioButton_b0_14_clicked();
    void on_radioButton_b0_15_clicked();

    void on_radioButton_c1_15_clicked();
    void on_radioButton_c1_14_clicked();
    void on_radioButton_c1_13_clicked();
    void on_radioButton_c1_12_clicked();
    void on_radioButton_c1_11_clicked();
    void on_radioButton_c1_10_clicked();
    void on_radioButton_c1_9_clicked();
    void on_radioButton_c1_8_clicked();
    void on_radioButton_c1_7_clicked();
    void on_radioButton_c1_6_clicked();
    void on_radioButton_c1_5_clicked();
    void on_radioButton_c1_4_clicked();
    void on_radioButton_c1_3_clicked();
    void on_radioButton_c1_2_clicked();
    void on_radioButton_c1_1_clicked();
    void on_radioButton_c1_0_clicked();

    void on_radioButton_c0_0_clicked();
    void on_radioButton_c0_1_clicked();
    void on_radioButton_c0_2_clicked();
    void on_radioButton_c0_3_clicked();
    void on_radioButton_c0_4_clicked();
    void on_radioButton_c0_5_clicked();
    void on_radioButton_c0_6_clicked();
    void on_radioButton_c0_7_clicked();
    void on_radioButton_c0_8_clicked();
    void on_radioButton_c0_9_clicked();
    void on_radioButton_c0_10_clicked();
    void on_radioButton_c0_11_clicked();
    void on_radioButton_c0_12_clicked();
    void on_radioButton_c0_13_clicked();
    void on_radioButton_c0_14_clicked();
    void on_radioButton_c0_15_clicked();

    void on_radioButton_d1_15_clicked();
    void on_radioButton_d1_14_clicked();
    void on_radioButton_d1_13_clicked();
    void on_radioButton_d1_12_clicked();
    void on_radioButton_d1_11_clicked();
    void on_radioButton_d1_10_clicked();
    void on_radioButton_d1_9_clicked();
    void on_radioButton_d1_8_clicked();
    void on_radioButton_d1_7_clicked();
    void on_radioButton_d1_6_clicked();
    void on_radioButton_d1_5_clicked();
    void on_radioButton_d1_4_clicked();
    void on_radioButton_d1_3_clicked();
    void on_radioButton_d1_2_clicked();
    void on_radioButton_d1_1_clicked();
    void on_radioButton_d1_0_clicked();

    void on_radioButton_d0_0_clicked();
    void on_radioButton_d0_1_clicked();
    void on_radioButton_d0_2_clicked();
    void on_radioButton_d0_3_clicked();
    void on_radioButton_d0_4_clicked();
    void on_radioButton_d0_5_clicked();
    void on_radioButton_d0_6_clicked();
    void on_radioButton_d0_7_clicked();
    void on_radioButton_d0_8_clicked();
    void on_radioButton_d0_9_clicked();
    void on_radioButton_d0_10_clicked();
    void on_radioButton_d0_11_clicked();
    void on_radioButton_d0_12_clicked();
    void on_radioButton_d0_13_clicked();
    void on_radioButton_d0_14_clicked();
    void on_radioButton_d0_15_clicked();

    void on_wpisz_button_a_clicked();
    void on_wpisz_button_c_clicked();
    void on_wpisz_button_b_clicked();
    void on_wpisz_button_d_clicked();


    void on_combo_box_order_currentIndexChanged(int index);

    void on_perform_order_button_clicked();

    void on_radioButton_in1_15_clicked();
    void on_radioButton_in1_14_clicked();
    void on_radioButton_in1_13_clicked();
    void on_radioButton_in1_12_clicked();
    void on_radioButton_in1_11_clicked();
    void on_radioButton_in1_10_clicked();
    void on_radioButton_in1_9_clicked();
    void on_radioButton_in1_8_clicked();
    void on_radioButton_in1_7_clicked();
    void on_radioButton_in1_6_clicked();
    void on_radioButton_in1_5_clicked();
    void on_radioButton_in1_4_clicked();
    void on_radioButton_in1_3_clicked();
    void on_radioButton_in1_2_clicked();
    void on_radioButton_in1_1_clicked();
    void on_radioButton_in1_0_clicked();
    void on_radioButton_in0_15_clicked();
    void on_radioButton_in0_14_clicked();
    void on_radioButton_in0_13_clicked();
    void on_radioButton_in0_12_clicked();
    void on_radioButton_in0_11_clicked();
    void on_radioButton_in0_10_clicked();
    void on_radioButton_in0_9_clicked();
    void on_radioButton_in0_8_clicked();
    void on_radioButton_in0_7_clicked();
    void on_radioButton_in0_6_clicked();
    void on_radioButton_in0_5_clicked();
    void on_radioButton_in0_4_clicked();
    void on_radioButton_in0_3_clicked();
    void on_radioButton_in0_2_clicked();
    void on_radioButton_in0_1_clicked();
    void on_radioButton_in0_0_clicked();

    void on_combo_box_two_currentIndexChanged(int index);

    void on_save_order_button_clicked();

    void on_save_program_button_clicked();

    void on_load_program_button_clicked();

    void display_program();

    void display_order_numbers(int numer_aktualnego_rozkazu);

    void on_perform_step_button_clicked();

    void on_perform_program_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
