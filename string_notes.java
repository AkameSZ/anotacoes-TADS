import java.util.Scanner;

public class string_notes {
    public static void main(String[] args) {
        
        //  # MONTAR UM CHAR DE 3 ÍNDICES E PASSAR UM FOR MOSTRANDO O VALOR DE CADA ÍNDICE
/*
        char chars[] = { 'a', 'b', 'c' };
        String str = new String(chars);
        
        for(int i = 0; 1 < str.length(); i++) {
            System.out.println("O caractere de índice " + i + " é: " + str.charAt(i));
            }
*/
         
        /* #################################################################################### */    

        //  # CONVERSOR DE MAIUSCULO/MINUSCULO COM UM WHILE PARA FAZER O PROGRAMA ENCHER
        //    O SACO DO USUARIO PARA ELE DIGITAR ALGO
/*
        Scanner scanner = new Scanner(System.in);
        String str;
        System.out.print("Informe uma palavra/frase em maiúsculo para conversão: ");
        str = scanner.nextLine();

        while (str.isEmpty()) {
            System.out.print("Por favor, insira algo: ");
            str = scanner.nextLine();
            
            }
            scanner.close();
            
            System.out.println("Maiúsculo: " + str.toUpperCase());
            System.out.println("Minúsculo: " + str.toLowerCase());
*/
           
        /* #################################################################################### */ 

        //  OVERVIEW DO MÉTODO CONCAT USADO EM UM SLIDE PRA POO

/*
           public class concat {
            public static void main(String[] args) {
                
            String nome = "Seu ", sobrenome = "Joao";
            System.out.println(nome.concat(sobrenome));
            
            // NESSE EXEMPLO ELE CONCATENA EM UMA VARIÁVEL COM VALOR JA PREDESTINADO
            String nome = "Luiz ";
            nome = nome.concat("Henrique");
            System.out.println(nome);
 */

        /* #################################################################################### */ 
        /*                                    ATIVIDADES                                        */
        /* #################################################################################### */ 
        
        //  ESPERA UM NUMERO. SE FOR 1 OU MAIOR, MOSTRA A RAIZ, SE MENOR, MOSTRA O QUADRADO

/*
        Scanner scanner = new Scanner(System.in);

        System.out.print(
                "Digite um número inteiro qualquer. Nùmeros positivos serão transformados em suas
                 raízes e negativos e iguais a zero serão elevados ao quadrado: ");
        int n = scanner.nextInt();

        if (n > 0) {
            System.out.printf("raiz: " + Math.sqrt(n));
        } else {
            System.out.printf("quadrado: " + (n * n));
        }

        scanner.close();
*/

        /* #################################################################################### */

        // O USUARIO VAI INSERIR UMA STRING, MOSTRE SEU TAMANHO, ALEM DE SEU TAMANHO JUNTO DA
        //  PRIMEIRA E ÚLTIMA LETRA

/*
        Scanner scanner = new Scanner(System.in);

        System.out.print("Insira uma palavra: ");
        String txt = scanner.nextLine();

        System.out.println("A sua palavra possui " + txt.length() + " letras");
        System.out.println("A primeira letra é: " + txt.charAt(0) + " e a ultima
         e: " + txt.charAt(txt.length() - 1));
*/

        /* #################################################################################### */

        // Construa um programa que receba 3 parâmetros (1° nome do usuário; 2° email;
        // 3° telefone) e exiba-os sem espaços e somente com letras maiúsculas.

/*
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite seu nome: ");
        String nome = scanner.nextLine();

        System.out.print("Digite seu email: ");
        String email = scanner.nextLine();

        System.out.print("Digite seu telefone: ");
        String telefone = scanner.nextLine();

        System.out.printf("Nome: " + nome.toUpperCase().trim() + "\nEmail: " +
         email.toUpperCase().trim() + "\nTelefone: " + telefone.toUpperCase().trim());

        scanner.close();
*/

        /* #################################################################################### */ 

        // ESPERA UMA STRING E RETORNA ELA AO CONTRÁRIO

/*
        Scanner scanner = new Scanner(System.in);

        System.out.print("String a ser invertida: ");
        String str = scanner.nextLine();

        String rwd = new StringBuilder(str).reverse().toString();

        System.out.println("Frase invertida: " + rwd);

        scanner.close();
*/      
        }
}