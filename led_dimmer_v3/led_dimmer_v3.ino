// Program ini mengontrol kecerahan lampu AC dengan menggunakan interrupt dan modulasi lebar pulsa (PWM).
// Potentiometer digunakan untuk mengubah kecerahan lampu.

int LAMP = 11; // Pin digital untuk mengontrol lampu
int dim_val = 0; // Nilai untuk mengontrol kecerahan lampu

// Fungsi setup() dijalankan saat program pertama kali dijalankan
void setup()
{
  pinMode(LAMP, OUTPUT); // Tetapkan lampu sebagai output
  attachInterrupt(digitalPinToInterrupt(2), zero_cross, CHANGE); // Pasang interrupt ke pin digital 2
}

// Fungsi zero_cross() dipanggil saat terjadi perubahan pada pin digital 2
void zero_cross()
{
  // Hitung waktu lampu menyala dalam mikrodetik
  int dimming_time = (200 * dim_val);

  // Tunggu selama waktu dimming_time
  delayMicroseconds(dimming_time);

  // Nyalakan lampu selama 10 mikrodetik
  digitalWrite(LAMP, HIGH);
  delayMicroseconds(10);
  digitalWrite(LAMP, LOW);
}

// Fungsi loop() dijalankan secara terus-menerus setelah setup() selesai dijalankan
void loop()
{
  // Baca nilai dari potentiometer
  int data = analogRead(A0);

  // Petakan nilai dari potentiometer ke rentang 10 hingga 49
  int dim_val_scaled = map(data, 0, 1023, 10, 49);

  // Atur nilai dim_val dengan nilai dim_val_scaled
  dim_val = dim_val_scaled;
}
