package html.git;

public class atividades_java {
    
    /* CALCULADORA COM AS 4 OPERAÇÕES
    import java.util.Scanner;

public class calculadora {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("===== MENU DE OPERAÇÕES =====");
        System.out.println("1 - Soma");
        System.out.println("2 - Multiplicação");
        System.out.println("3 - Divisão");
        System.out.println("4 - Subtração");
        System.out.print("Escolha uma opção: ");
        int opcao = scanner.nextInt();

        System.out.print("Digite o primeiro número: ");
        double num1 = scanner.nextDouble();

        System.out.print("Digite o segundo número: ");
        double num2 = scanner.nextDouble();

        double resultado;

        switch (opcao) {
            case 1:
                resultado = num1 + num2;
                System.out.printf("Resultado da soma: %.2f%n", resultado);
                break;

            case 2:
                resultado = num1 * num2;
                System.out.printf("Resultado da multiplicação: %.2f%n", resultado);
                break;

            case 3:
                if (num2 != 0) {
                    resultado = num1 / num2;
                    System.out.printf("Resultado da divisão: %.2f%n", resultado);
                } else {
                    System.out.println("Erro: não é possível dividir por zero!");
                }
                break;

            case 4:
                resultado = num1 - num2;
                System.out.printf("Resultado da subtração: %.2f%n", resultado);
                break;

            default:
                System.out.println("Opção inválida! Escolha um valor entre 1 e 4.");
                break;
        }

        scanner.close();
    }
} */    //TROCA DE VALOR DE VARIAVEIS

    /*import java.util.Scanner;

public class troca {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite o valor de A: ");
        double a = scanner.nextDouble();

        System.out.print("Digite o valor de B: ");
        double b = scanner.nextDouble();

        System.out.println("\nAntes da troca:");
        System.out.println("A = " + a);
        System.out.println("B = " + b);

        // Troca usando variável auxiliar
        double auxiliar = a;
        a = b;
        b = auxiliar;

        System.out.println("\nDepois da troca:");
        System.out.println("A = " + a);
        System.out.println("B = " + b);

        scanner.close();
    }
} */    //CALCULADORA DE MEDIA

    /*import java.util.Scanner;

public class media {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite a primeira nota: ");
        double nota1 = scanner.nextDouble();

        System.out.print("Digite a segunda nota: ");
        double nota2 = scanner.nextDouble();

        double media = (nota1 + nota2) / 2;

        System.out.printf("A média do aluno é: %.2f%n", media);

        scanner.close();
    }
} */    //AUMENTO DE SALARIO

    /*import java.util.Scanner;

public class salario {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Digite o salário atual do funcionário: ");
        double salarioAtual = scanner.nextDouble();

        double percentualAumento = 0.20;
        double valorAumento = salarioAtual * percentualAumento;
        double novoSalario = salarioAtual + valorAumento;

        System.out.printf("Valor do aumento: R$ %.2f%n", valorAumento);
        System.out.printf("Novo salário: R$ %.2f%n", novoSalario);

        scanner.close();
    }
} */    //ONDE BOTAR A GARRAFINHA

    /*import java.util.Scanner;

public class corrida {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int garrafa = 0;
        int metros_trajeto = 0;

        System.out.print("Informe a quantidade de metros a serem percorridos (1-100.000.000): ");
        int metros_a_correr = scanner.nextInt();

        if (metros_a_correr > 0 && metros_a_correr <= 100000000) {
            System.out.print("Informe a quantidade de metros da pista (1-100): ");
            metros_trajeto = scanner.nextInt();

            if (metros_trajeto > 0 && metros_trajeto <= 100) {
                garrafa = metros_a_correr % metros_trajeto;
                System.out.print(garrafa);

            } else {
                System.out.println("#### ERRO, FINALIZANDO PROGRAMA ####");
                System.exit(0);
            }
        } else {
            System.out.println("#### ERRO, FINALIZANDO PROGRAMA ####");
            System.exit(0);
        }
        scanner.close();
    }
} */
}