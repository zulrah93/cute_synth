#include <QFileDialog>
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./wave_t.hpp"

constexpr auto SAMPLE_RATE = 44100;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->generate_button, &QPushButton::clicked, this, [this]{
        QString wav_file_path = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                        "/home/",
                                                        tr("PCM Audio (*.wav)"));
        if (wav_file_path.isEmpty()) {
            ui->status_label->setText("Failed to save!");
            return;
        }
        const uint8_t osc_a_type = static_cast<uint8_t>(ui->oscillator_type_a->currentIndex()) + 1;
        const uint8_t osc_b_type = static_cast<uint8_t>(ui->oscillator_type_b->currentIndex()) + 1;
        const uint8_t osc_c_type = static_cast<uint8_t>(ui->oscillator_type_c->currentIndex()) + 1;
        const uint8_t osc_d_type = static_cast<uint8_t>(ui->oscillator_type_d->currentIndex()) + 1;
        const uint8_t osc_e_type = static_cast<uint8_t>(ui->oscillator_type_e->currentIndex()) + 1;
        const uint8_t osc_f_type = static_cast<uint8_t>(ui->oscillator_type_f->currentIndex()) + 1;
        const uint8_t osc_g_type = static_cast<uint8_t>(ui->oscillator_type_g->currentIndex()) + 1;
        const uint8_t wave_a_type = static_cast<uint8_t>(ui->wave_type_a->currentIndex()) + 1;
        const uint8_t wave_b_type = static_cast<uint8_t>(ui->wave_type_b->currentIndex()) + 1;
        const uint8_t wave_c_type = static_cast<uint8_t>(ui->wave_type_c->currentIndex()) + 1;
        const uint8_t wave_d_type = static_cast<uint8_t>(ui->wave_type_d->currentIndex()) + 1;
        const uint8_t wave_e_type = static_cast<uint8_t>(ui->wave_type_e->currentIndex()) + 1;
        const uint8_t wave_f_type = static_cast<uint8_t>(ui->wave_type_f->currentIndex()) + 1;
        const uint8_t wave_g_type = static_cast<uint8_t>(ui->wave_type_g->currentIndex()) + 1;
        const double frequency_a = static_cast<double>(ui->frequency_dial_a->value());
        const double frequency_b = static_cast<double>(ui->frequency_dial_b->value());
        const double frequency_c = static_cast<double>(ui->frequency_dial_c->value());
        const double frequency_d = static_cast<double>(ui->frequency_dial_d->value());
        const double frequency_e = static_cast<double>(ui->frequency_dial_e->value());
        const double frequency_f = static_cast<double>(ui->frequency_dial_f->value());
        const double frequency_g = static_cast<double>(ui->frequency_dial_g->value());
        wave_file_t synth_output;
        synth_output.set_sample_rate(SAMPLE_RATE);
        synth_output.set_number_of_channels(1);
        synth_output.set_bits_per_sample(24);

        synth_config_t configuration{};

        oscillator_type_t operator_type_a = oscillator_type_t::empty;

        switch (osc_a_type) {
            case 0: {
                operator_type_a = oscillator_type_t::empty;
                break;
            }
            case 1: {
                operator_type_a = oscillator_type_t::carrier;
                break;
            }
            case 2: {
                operator_type_a = oscillator_type_t::frequency_modulation;
                break;
            }
            default: {
                operator_type_a = oscillator_type_t::empty;
                break;
            }
        }

        oscillator_type_t operator_type_b = oscillator_type_t::empty;

        switch (osc_b_type) {
            case 0: {
                operator_type_b = oscillator_type_t::empty;
                break;
            }
            case 1: {
                operator_type_b = oscillator_type_t::carrier;
                break;
            }
            case 2: {
                operator_type_b = oscillator_type_t::frequency_modulation;
                break;
            }
            default: {
                operator_type_b = oscillator_type_t::empty;
                break;
            }
        }

        oscillator_type_t operator_type_c = oscillator_type_t::empty;

        switch (osc_c_type) {
            case 0: {
                operator_type_b = oscillator_type_t::empty;
                break;
            }
            case 1: {
                operator_type_c = oscillator_type_t::carrier;
                break;
            }
            case 2: {
                operator_type_c = oscillator_type_t::frequency_modulation;
                break;
            }
            default: {
                operator_type_c = oscillator_type_t::empty;
                break;
            }
        }


        oscillator_type_t operator_type_d = oscillator_type_t::empty;

        switch (osc_d_type) {
            case 0: {
                operator_type_d = oscillator_type_t::empty;
                break;
            }
            case 1: {
                operator_type_d = oscillator_type_t::carrier;
                break;
            }
            case 2: {
                operator_type_d = oscillator_type_t::frequency_modulation;
                break;
            }
            default: {
                operator_type_d = oscillator_type_t::empty;
                break;
            }
        }

        oscillator_type_t operator_type_e = oscillator_type_t::empty;

        switch (osc_e_type) {
            case 0: {
                operator_type_e = oscillator_type_t::empty;
                break;
            }
            case 1: {
                operator_type_e = oscillator_type_t::carrier;
                break;
            }
            case 2: {
                operator_type_e = oscillator_type_t::frequency_modulation;
                break;
            }
            default: {
                operator_type_e = oscillator_type_t::empty;
                break;
            }
        }

        oscillator_type_t operator_type_f = oscillator_type_t::empty;

        switch (osc_f_type) {
            case 0: {
                operator_type_f = oscillator_type_t::empty;
                break;
            }
            case 1: {
                operator_type_f = oscillator_type_t::carrier;
                break;
            }
            case 2: {
                operator_type_f = oscillator_type_t::frequency_modulation;
                break;
            }
            default: {
                operator_type_f = oscillator_type_t::empty;
                break;
            }
        }

        oscillator_type_t operator_type_g = oscillator_type_t::empty;

        switch (osc_g_type) {
            case 0: {
                operator_type_g = oscillator_type_t::empty;
                break;
            }
            case 1: {
                operator_type_g = oscillator_type_t::carrier;
                break;
            }
            case 2: {
                operator_type_g = oscillator_type_t::frequency_modulation;
                break;
            }
            default: {
                operator_type_g = oscillator_type_t::empty;
                break;
            }
        }

        configuration.oscillator_a.operator_type = operator_type_a;
        configuration.oscillator_a.wave_type = wave_a_type;
        configuration.oscillator_a.frequency = frequency_a;
        configuration.oscillator_a.osc_to_modulate =
            oscillator_selection_t::none_selected;

        configuration.oscillator_b.operator_type = operator_type_b;
        configuration.oscillator_b.wave_type = wave_b_type;
        configuration.oscillator_b.frequency = frequency_b;
        configuration.oscillator_b.osc_to_modulate = oscillator_selection_t::none_selected;

        configuration.oscillator_c.operator_type = operator_type_c;
        configuration.oscillator_c.wave_type = wave_c_type;
        configuration.oscillator_c.frequency = frequency_c;
        configuration.oscillator_c.osc_to_modulate =
            oscillator_selection_t::none_selected;

        configuration.oscillator_d.operator_type = operator_type_d;
        configuration.oscillator_d.wave_type = wave_d_type;
        configuration.oscillator_d.frequency = frequency_d;
        configuration.oscillator_d.osc_to_modulate =
            oscillator_selection_t::none_selected;

        configuration.oscillator_e.operator_type = operator_type_e;
        configuration.oscillator_e.wave_type = wave_e_type;
        configuration.oscillator_e.frequency = frequency_e;
        configuration.oscillator_e.osc_to_modulate =
            oscillator_selection_t::none_selected;

        configuration.oscillator_f.operator_type = operator_type_f;
        configuration.oscillator_f.wave_type = wave_f_type;
        configuration.oscillator_f.frequency = frequency_f;
        configuration.oscillator_f.osc_to_modulate =
            oscillator_selection_t::none_selected;

        configuration.oscillator_g.operator_type = operator_type_g;
        configuration.oscillator_g.wave_type = wave_g_type;
        configuration.oscillator_g.frequency = frequency_g;
        configuration.oscillator_g.osc_to_modulate =
            oscillator_selection_t::none_selected;

        constexpr size_t seconds = 3ul;

        const size_t synth_sample_size = SAMPLE_RATE * seconds;

        if (synth_output.generate_synth(synth_sample_size, 0.12, configuration)) {
            bool success = synth_output.save(wav_file_path.toStdString());
            ui->status_label->setText(success ? "Saved sucessfully!!" : "Failed to save!");
        } else {
            ui->status_label->setText("Failed to generate synth!!");
        }

    });
    connect(dynamic_cast<QAbstractSlider*>(ui->frequency_dial_a), &QAbstractSlider::valueChanged, this, [this](int new_frequency) {
        std::string frequency_str = std::to_string(new_frequency);
        frequency_str += " Hz";
        ui->freq_label_a->setText(frequency_str.c_str());
    });
    connect(dynamic_cast<QAbstractSlider*>(ui->frequency_dial_b), &QAbstractSlider::valueChanged, this, [this](int new_frequency) {
        std::string frequency_str = std::to_string(new_frequency);
        frequency_str += " Hz";
        ui->freq_label_b->setText(frequency_str.c_str());
    });
    connect(dynamic_cast<QAbstractSlider*>(ui->frequency_dial_c), &QAbstractSlider::valueChanged, this, [this](int new_frequency) {
        std::string frequency_str = std::to_string(new_frequency);
        frequency_str += " Hz";
        ui->freq_label_c->setText(frequency_str.c_str());
    });
    connect(dynamic_cast<QAbstractSlider*>(ui->frequency_dial_d), &QAbstractSlider::valueChanged, this, [this](int new_frequency) {
        std::string frequency_str = std::to_string(new_frequency);
        frequency_str += " Hz";
        ui->freq_label_d->setText(frequency_str.c_str());
    });
    connect(dynamic_cast<QAbstractSlider*>(ui->frequency_dial_e), &QAbstractSlider::valueChanged, this, [this](int new_frequency) {
        std::string frequency_str = std::to_string(new_frequency);
        frequency_str += " Hz";
        ui->freq_label_e->setText(frequency_str.c_str());
    });
    connect(dynamic_cast<QAbstractSlider*>(ui->frequency_dial_f), &QAbstractSlider::valueChanged, this, [this](int new_frequency) {
        std::string frequency_str = std::to_string(new_frequency);
        frequency_str += " Hz";
        ui->freq_label_f->setText(frequency_str.c_str());
    });
    connect(dynamic_cast<QAbstractSlider*>(ui->frequency_dial_g), &QAbstractSlider::valueChanged, this, [this](int new_frequency) {
        std::string frequency_str = std::to_string(new_frequency);
        frequency_str += " Hz";
        ui->freq_label_g->setText(frequency_str.c_str());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
