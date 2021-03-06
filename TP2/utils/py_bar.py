import matplotlib.pyplot as plt
import numpy as np


n_labels = ["0", "100", "500", "1000", "5000", "10000", "50000", "100000", "200000"]

time_hs_ms = [0.038561, 0.230284, 0.494513, 3.00514, 6.38121, 39.2721, 80.9178, 181.019]
time_hs_s = [i / 1000 for i in time_hs_ms]

time_qs_ms = [0.01502, 0.096148, 0.195295, 1.01146, 2.12003, 11.9156, 24.6517, 51.1312]
time_qs_s = [i / 1000 for i in time_qs_ms]

time_qso_ms = [
    0.036744,
    0.178842,
    0.341509,
    1.77083,
    3.66662,
    20.6795,
    45.8731,
    97.4092,
]
time_qso_s = [i / 1000 for i in time_qso_ms]

time_shell_ms = [
    0.029607,
    0.146835,
    0.360094,
    2.23231,
    5.08222,
    34.346,
    74.2509,
    163.771,
]
time_shell_s = [i / 1000 for i in time_qso_ms]

width_bars = 0.2
n_size = np.arange(8)

fig = plt.figure()
ax = fig.add_axes([0.09, 0.08, 0.8, 0.8])

ax.set_title("Tempo em Função do Tamanho da Entrada - Aleatória")
ax.set_ylabel("Tempo em Milisegundos")
ax.set_xlabel("N linhas consideradas")

rect1 = ax.bar(n_size, time_hs_ms, color="r", width=width_bars)
rect2 = ax.bar(n_size + width_bars, time_qs_ms, color="b", width=width_bars)
rect3 = ax.bar(n_size + 2 * width_bars, time_qso_ms, color="g", width=width_bars)
rect4 = ax.bar(n_size + 3 * width_bars, time_shell_ms, color="grey", width=width_bars)


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


autolabel(rect1)
autolabel(rect2)
autolabel(rect3)
autolabel(rect4)

ax.set_xticklabels(n_labels)
ax.legend(
    title="Ordenacao da Entrada",
    labels=["Heap Sort", "Quick Sort", "QS Otimizado", "Shell Sort"],
)
plt.show()
