#include <stdio.h>

float converteMetrosCubicosParaLitro(float metrosCubicos){
    float litros = metrosCubicos*1000;
    return litros;
}
// 1m³ == 1000 litros

float converteGaloesParaMetrosCubicos(int galao){
    float galaoParaMetroCubico = galao * 0.00378541;
    return galaoParaMetroCubico;
}

float calculaVolumeTotalEmLitros(float volumeDosTanques, float volumeDosGaloes){
    float valorTanqueEmLitro = converteMetrosCubicosParaLitro(volumeDosTanques);
    float galoesm3 =  converteGaloesParaMetrosCubicos(volumeDosGaloes);
    float valorGaloesEmLitro = converteMetrosCubicosParaLitro(galoesm3); 
    return (valorTanqueEmLitro + valorGaloesEmLitro);
}

float calculaCustoIrrigacao(float totalEmLitros, int modalidadeDeIrrigacao){
    if (modalidadeDeIrrigacao == 1){
        return totalEmLitros * 0.03;
    }
    else if (modalidadeDeIrrigacao == 2){
        return totalEmLitros * 0.05;
    }
    else{
        if (totalEmLitros <= 5000){
            return totalEmLitros * 0.09;
        }
        else{
            return totalEmLitros * 0.07;
        }
    }
    
    if (totalEmLitros > 30000){
        return totalEmLitros + 180;
    }
    return totalEmLitros;
}

int main(){
    int volumeEmM3, volumeEmGaloes, modalidade;
    printf("Insira o volume em m³: ");
    scanf("%d", &volumeEmM3);
    printf("Insira o volume em galões: ");
    scanf("%d", &volumeEmGaloes);
    printf("Insira a modalidade de irrigação: ");
    scanf("%d", &modalidade);
    float TotalEmLitro = calculaVolumeTotalEmLitros(volumeEmM3, volumeEmGaloes);
    printf("Volume total: %.2f\n", TotalEmLitro);
    float custoTotal = calculaCustoIrrigacao(TotalEmLitro, modalidade);
    printf("Valor total a pagar: %.2f\n", custoTotal);
    return 0;
}