import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

/**
 * Created by Андрей on 16.04.2018.
 */

class Person{
    String name;
    int phone;
    String email;
    ArrayList phoneList = new ArrayList();
    ArrayList emailList = new ArrayList();
    Person(){
        this.name="";
        this.phone = 0;
        this.email="";
    }
    Person(    String name,
               int phone,
               String email){
        this.name = name;
        this.phone = phone;
        this.email = email;
        this.phoneList.add(phone);
        this.emailList.add(email);
    }
    Person(String name){
        this.name = name;
    }
    Person(String name,int phone){
        this.name = name;
        this.phone = phone;
        this.phoneList.add(phone);
    }
    Person(String name,String email) {
        this.name = name;
        this.email = email;
        this.emailList.add(email);
    }
}

class PhoneBook {
    HashMap<String, Person> phonebook = new HashMap<>();
    void add(Person person){
        if (phonebook.get(person.name)!=null) {
            person.phoneList.addAll(phonebook.get(person.name).phoneList);
            person.emailList.addAll(phonebook.get(person.name).emailList);
        }
        phonebook.put(person.name,person);
    };
    ArrayList searchPhone(String name){
        return phonebook.get(name).phoneList;
    }
    ArrayList searchEmail(String name){
        return phonebook.get(name).emailList;
    }
}

class Main{
    public static void main(String[] args) {
        //ЗАДАЧА 1. Подсчет кол-ва слов в строке используя hashMap
        String s = "welcome to fight club " +
                "the first rule of fight club is you do not talk about fight club " +
                "the second rule of fight club is you do not talk about fight club " +
                "and the eighth and final rule if this is your first time at fight club you have to fight";
        String[] arrayString  = s.split(" ");
        HashMap<String,Integer> hm = new HashMap<>();
        for (int i = 0; i < arrayString.length; i++){
            if (hm.containsKey(arrayString[i]))
                hm.put(arrayString[i],hm.get(arrayString[i])+1);
            else
                hm.put(arrayString[i],1);
        }
        Set<Map.Entry<String,Integer>> set = hm.entrySet();
        System.out.println("original text: " + s);
        System.out.println("counting words...");
        for (Map.Entry<String,Integer> o: set){
            System.out.print(o.getKey() + "=" + o.getValue() + "; ");
        }

        //////////////////////////
        System.out.println();
        System.out.println();
        /////////////////////////
        //ЗАДАЧА 2. Создание телефонной книги в виде HashMap и поиск телефона/адреса по фамилии
        /////////////////////////
        PhoneBook tel = new PhoneBook();
        Person person = new Person("IVANOV",322222,"ivanov@mail.ru");
        Person person2 = new Person("IVANOV",8917384,"ivanivan@mail.ru");
        Person person3 = new Person("IVANOV",111,"ivan98@mail.ru");
        Person person4 = new Person("SIDOROV",03,"sidorov@mail.ru");
        Person person5 = new Person("KOTOV",33636363,"kotov@mail.ru");
        Person person6 = new Person("VASILIEV",26754747,"vasiliev@mail.ru");
        Person person7 = new Person("PETROV",288888,"petrov88@mail.ru");
        Person person8 = new Person("KOTOV",8765,"kot@mail.ru");
        Person person9 = new Person("PETROV",2674843,"petrov@mail.ru");
        Person person10 = new Person("IVANOV",9994565);
        tel.add(person);
        tel.add(person2);
        tel.add(person3);
        tel.add(person4);
        tel.add(person5);
        tel.add(person6);
        tel.add(person7);
        tel.add(person8);
        tel.add(person9);
        tel.add(person10);
        System.out.println(tel.searchPhone("IVANOV"));
        System.out.println(tel.searchEmail("IVANOV"));
        System.out.println(tel.searchPhone("PETROV"));
        System.out.println(tel.searchEmail("KOTOV"));
        System.out.println(tel.searchEmail("SIDOROV"));
    }
}