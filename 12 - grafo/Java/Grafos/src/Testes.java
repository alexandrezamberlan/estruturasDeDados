
import java.util.LinkedList;
import java.util.Queue;

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author laboratorio
 */
public class Testes {
    public static void main(String[] args) {
//        String frase = "alex@ndre em ação";
//        System.out.println(frase.toUpperCase());

        Queue<String> fila = new LinkedList<>();
        fila.add("andre");
        System.out.println(fila.poll());
        System.out.println(fila.poll());
        
    }
    
}
