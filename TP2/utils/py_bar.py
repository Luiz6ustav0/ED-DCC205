import matplotlib.pyplot as plt
import numpy as np


n_labels = ["0", "100", "500", "1000", "5000",
            "10000", "50000", "100000", "200000"]

time_hs_ms = [0.01701, 0.098306, 0.211622,
              1.37833, 2.91382, 15.0288, 31.7789, 66.265]

time_qs_ms = [0.006589, 0.021788, 0.041724,
              0.199159, 0.395223, 2.02823, 4.4741, 9.15899]

time_qso_ms = [
    0.023298, 0.106826, 0.188282, 0.932573, 2.20175, 11.0447, 23.9959, 52.9057
]

time_shell_ms = [
    0.010127, 0.073522, 0.142917, 0.984724, 2.30669, 12.8059, 27.4113, 58.4057
]

time_insertion_ms = [0.00273, 0.011746, 0.020674,
                     0.089732, 0.178546, 0.925858, 1.88407, 3.75651]

width_bars = 0.18
n_size = np.arange(8)

for i in range(8):
    time_hs_ms[i] *= 2
    time_qs_ms[i] *= 2
    time_qso_ms[i] *= 2
    time_shell_ms[i] *= 2

fig = plt.figure()
ax = fig.add_axes([0.09, 0.08, 0.8, 0.8])

ax.set_title("Tempo em Função do Tamanho da Entrada - Decrescente")
ax.set_ylabel("Tempo em Milisegundos")
ax.set_xlabel("N linhas consideradas")

rect1 = ax.bar(n_size, time_hs_ms, color="r", width=width_bars)
rect2 = ax.bar(n_size + width_bars, time_qs_ms, color="b", width=width_bars)
rect3 = ax.bar(n_size + 2 * width_bars, time_qso_ms,
               color="g", width=width_bars)
rect4 = ax.bar(n_size + 3 * width_bars, time_shell_ms,
               color="grey", width=width_bars)
rect4 = ax.bar(n_size + 4 * width_bars, time_insertion_ms,
               color="yellow", width=width_bars)


def autolabel(rects):
    """Attach a text label above each bar in *rects*, displaying its height."""
    for rect in rects:
        height = rect.get_height()
        if height > 1:
            ax.annotate(
                "{:.1f}".format(height),
                xy=(rect.get_x() + rect.get_width() / 2, height),
                xytext=(0, 3),  # 3 points vertical offset
                textcoords="offset points",
                ha="center",
                va="bottom",
            )


ax.grid(True)

ax.set_xticklabels(n_labels)
ax.legend(
    title="Ordenacao da Entrada",
    labels=["Heap Sort", "Quick Sort", "QS Otimizado", "Shell Sort", "Insertion Sort"],
)
plt.show()
