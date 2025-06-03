import pandas as pd
import matplotlib.pyplot as plt

# === Parte 1: Gráficos de ordenação por arquivo ===
df = pd.read_csv("resultados.csv", header=None,
                 names=["Algoritmo", "Arquivo", "Tempo(ms)", "Comparacoes", "Trocas"])

arquivos = ["../dados/pequeno.bin", "../dados/medio.bin", "../dados/grande.bin"]

for arq in arquivos:
    df_filtrado = df[df['Arquivo'] == arq]
    if df_filtrado.empty:
        print(f"Aviso: Nenhum dado para {arq}")
        continue

    # Tempo x Algoritmo
    plt.figure(figsize=(10,8))
    plt.bar(df_filtrado['Algoritmo'], df_filtrado['Tempo(ms)'], color='skyblue', width=0.3)
    plt.title(f"Tempo de Execução - {arq.split('/')[-1]}")
    plt.xlabel("Algoritmo")
    plt.ylabel("Tempo (ms)")
    plt.xticks(rotation=45)
    plt.tight_layout()
    plt.savefig(f"../images/grafico_tempo_{arq.split('/')[-1].replace('.bin','')}.png")
    plt.show()

    # Comparações x Algoritmo
    plt.figure(figsize=(10,8))
    plt.bar(df_filtrado['Algoritmo'], df_filtrado['Comparacoes'], color='lightgreen', width=0.3)
    plt.title(f"Número de Comparações - {arq.split('/')[-1]}")
    plt.xlabel("Algoritmo")
    plt.ylabel("Comparações")
    plt.xticks(rotation=45)
    plt.tight_layout()
    plt.savefig(f"../images/grafico_comparacoes_{arq.split('/')[-1].replace('.bin','')}.png")
    plt.show()

    # Trocas x Algoritmo
    plt.figure(figsize=(10,8))
    plt.bar(df_filtrado['Algoritmo'], df_filtrado['Trocas'], color='salmon', width=0.3)
    plt.title(f"Número de Trocas - {arq.split('/')[-1]}")
    plt.xlabel("Algoritmo")
    plt.ylabel("Trocas")
    plt.xticks(rotation=45)
    plt.tight_layout()
    plt.savefig(f"../images/grafico_trocas_{arq.split('/')[-1].replace('.bin','')}.png")
    plt.show()


# === Parte 2: Gráficos separados para buscas (Sequencial vs Binária) ===
df_buscas = pd.read_csv("buscas.csv")

# --- Tempo x Tipo de Busca ---
plt.figure(figsize=(10,8))
for tipo in df_buscas["Tipo"].unique():
    subset = df_buscas[df_buscas["Tipo"] == tipo]
    plt.plot(subset["Arquivo"], subset["Tempo(ms)"], marker='o', label=tipo)

plt.title("Tempo de Execução - Busca Sequencial vs Binária")
plt.xlabel("Arquivo")
plt.ylabel("Tempo (ms)")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("../images/grafico_busca_tempo.png")
plt.show()

# --- Comparações x Tipo de Busca ---
plt.figure(figsize=(10,8))
for tipo in df_buscas["Tipo"].unique():
    subset = df_buscas[df_buscas["Tipo"] == tipo]
    plt.plot(subset["Arquivo"], subset["Comparacoes"], marker='s', label=tipo)

plt.title("Número de Comparações - Busca Sequencial vs Binária")
plt.xlabel("Arquivo")
plt.ylabel("Comparações")
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("../images/grafico_busca_comparacoes.png")
plt.show()