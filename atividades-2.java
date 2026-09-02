import java.util.Scanner;

public class activities2 {
    public static void main(String[] args) {

        /* #################################################################################### */ 
        /*                                  ATIVIDADES                                          */
        /* #################################################################################### */ 
        
        //  ESPERA UM NÚMERO INTEIRO. CASO POSITIVO, ENTREGA A RAIZ DESSE NÚMERO,
        //  CASO NEGATIVO, ENTREGA SEU QUADRADO
/*
        Scanner scanner = new Scanner(System.in);

        System.out.print(
                "Digite um número inteiro qualquer. Nùmeros positivos serão transformados em 
                suas raízes e negativos e iguais a zero serão elevados ao quadrado: ");
        int n = scanner.nextInt();

        if (n > 0) {
            System.out.printf("raiz: " + Math.sqrt(n));
        } else {
            System.out.printf("quadrado: " + (n * n));
        }
*/

        /* #################################################################################### */

        // ESPERA UM NÚMERO E VERIFICA SE ELE É DIVISIVEL POR 3 E POR 7
/*
        Scanner scanner = new Scanner(System.in);

        System.out.printf("Insira um número divisivel por 3 E por 7: ");
        int n = scanner.nextInt();

        if (n % 3 == 0 && n % 7 == 0) {
            System.out.println("O numero " + n + " e divisivel por 3 e por 7!");
        } else {
            System.out.println(n + " NAO E DIVISIVEL POR 3 OU POR 7 SEU BURRO");
        }
        scanner.close();
*/  

        /* #################################################################################### */

        //  CALCULA SE O USUARIO PODE SOLICITAR UM EMPRESTIMO, SABENDO QUE O EMPRSTIMO SO PODE SER
        //  ACEITO SE O VALOR FOR ATE 30% DE SEU SALARIO TOTAL

/*
        Scanner scanner = new Scanner(System.in);

        System.out.printf("Insira seu salario: R$");
        double salario = scanner.nextFloat();
        
        System.out.printf("\nInsira o valor do emprestimo: R$");
        double emprestimo = scanner.nextFloat();

        double corte = 0.3 * salario;

        if (emprestimo <= corte) {
            System.out.println("emprestimo aprovado!");
        } else {
            System.out.printf("\nEmprestimo negado!\nValor máximo de emprestimo: R$%.2f", corte);   
        }

        scanner.close();
*/

        /* #################################################################################### */

        //  ORDENAR 3 NUMEROS DO MAIOR PRO MENOR, SIMPLES DE FALAR E COMPLICADO DE FAZER

/*
        Scanner scanner = new Scanner(System.in);

        System.out.print("Insira o primeiro numero: ");
        int a = scanner.nextInt();
        System.out.print("Insira o segundo numero: ");
        int b = scanner.nextInt();
        System.out.print("Insira o terceiro numero: ");
        int c = scanner.nextInt();

        int temp;

        if (a < b) {
            temp = a;
            a = b;
            b = temp;
        }
        if (b < c) {
            temp = b;
            b = c;
            c = temp;
        }
        if (a < b) {
            temp = a;
            a = b;
            b = temp;     //  cachorrada da bixiga pra fazer isso, odeio
        }

        scanner.close();
        System.out.printf("Numeros ordenados decrescentemente: " + a + ", " + b + " e " + c);
*/
    }
}
