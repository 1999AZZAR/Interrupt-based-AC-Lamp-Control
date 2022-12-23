<h1>Pengaturan Kecerahan Lampu AC</h1>

<p>Program ini menggunakan interrupt dan modulasi lebar pulsa (PWM) untuk mengatur kecerahan lampu AC. Kecerahan dapat diubah dengan menggunakan potentiometer yang terhubung ke pin analog A0.</p>

<h2>Pengaturan</h2>

<ol>
  <li>Hubungkan lampu AC ke pin digital 11 pada Arduino.</li>
  <li>Hubungkan potentiometer ke pin analog A0 pada Arduino.</li>
</ol>

<h2>Fungsi</h2>

<h3><code>setup()</code></h3>

<p>Dalam fungsi <code>setup()</code>, lampu ditetapkan sebagai output dan interrupt terpasang ke pin digital 2. Fungsi interrupt disebut <code>zero_cross()</code>.</p>

<h3><code>zero_cross()</code></h3>

<p>Fungsi <code>zero_cross()</code> dipanggil setiap kali terjadi perubahan pada pin digital 2. Di dalam fungsi, variabel <code>dimming_time</code> dihitung menggunakan nilai dari variabel <code>dim_val</code>. Kemudian, lampu dinyalakan selama waktu singkat dan kemudian dimatikan lagi. Panjang waktu lampu menyala ditentukan oleh variabel <code>dimming_time</code>, yang mengontrol kecerahan lampu.</p>

<h3><code>loop()</code></h3>

<p>Dalam fungsi <code>loop()</code>, nilai dari potentiometer dibaca dari pin analog A0 dan dipetakan ke rentang 10 hingga 49. Nilai ini kemudian diberikan ke variabel <code>dim_val</code>, yang digunakan dalam fungsi <code>zero_cross()</code> untuk mengontrol kecerahan lampu.</p>
