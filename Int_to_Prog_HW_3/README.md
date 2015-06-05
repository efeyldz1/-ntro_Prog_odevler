###Istanbul University – Computer Engineering
###Introduction to Programming – Homework 3
###Labirent Ödevi

Kibrit coplerinden olusturulacak bir kare izgarada, ust koseden baslayarak ( 0,0) alt koseye (n,n)
gidecek yolu belirleyecek bir labirent cozme uygulamasi yazilacaktir. Kibrit coplerinin uclari labirentin o
cizgisi uzerinde gidilebilecegi yonu gosterecektir. Labirent bilgisi kullanicidan alinacaktir. Izgaradaki
her hucre 16 lik sayi sistemindeki bir rakam ile temsil edilecektir. ( 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F) 16
lik sistemdeki her rakam cevresindeki kibrit coplerinin durumunu belirleyen bir bilgi icermektedir. Her
hucre 4 cephesindeki kibrit coplerinin yonunu kendisinde bilgi olarak barindirmaktadir. Eger kibrit copu
saat yonunde yerlestirilmis ise(ilgili hucreye gore) 0 degilse 1 ile temsil edilecektir. Her hucre sirasi
ile ust , sag , alt , sol tarafindaki kibrit coplerinin konum bilgilerinin bir araya getirilerek olusan 4
bitlik bir sayidan meydana gelecektir. Ornegin 0 : (0000) her tarafindaki kibrit copleri saat yonunde
yerlestirildi demektir. 7 : (0111) ust tarafindaki kibrit copu saat yonune digerleri ise saat yonunun
tersine bakiyor demektir.

Program kullanicidan kare matris boyutunu ve izgaradaki her hucrenin degerini isteyecektir. Eger girilen
rakamlarda bir tutarsizlik varsa “girilen degerler tutarsiz” diyerek yeni degerleri isteyecektir.

Program alacagi bilgilere gore ust sol kose noktasindan alt sag kose noktasina gidebilecek bir yol olup
olmadigini kontrol edecek. Eger yol yok ise "yol yok" cevabini donecek. Eger bir yol bulunabiliyor ise "yol
var" cevabini donecek ve uygun yolu sol , sag , asagi , yukari ifadeleri ile tanimlayacak.

![alt text](https://fatihbozik.files.wordpress.com/2015/02/resim1.png) <img align="right" src="https://fatihbozik.files.wordpress.com/2015/02/resim5.png">

**Örnek 1:** <br/>
Matris Boyutu : 3 <br/> <img align="right" src="https://fatihbozik.files.wordpress.com/2015/02/resim2.png">
Degerler ( her satirda 3 deger olacak sekilde <br/>
satir bazli giriliyor) : 0 1 D C 8 D 8 F A  
 
**Cikti :** <br/>
Tutarli <br/>
Yol var <br/>
sol sol asagi asagi sag asagi sol sol <br/> 

--

**Örnek 2:** <br/> <img align="right" src="https://fatihbozik.files.wordpress.com/2015/02/resim3.png">
Matris Boyutu : 2 <br/>
Degerler : 0 7 8 7 <br/>

**Cikti :** <br/> 
Tutarli <br/>
Yol Var <br/>
sol asagi asagi sol <br/>

--

**Örnek 3:** <br/> <img align="right" src="https://fatihbozik.files.wordpress.com/2015/02/resim4.png">
Matris Boyutu : 2 <br/>
Degerler : 5 5 D C <br/>

**Cikti :** <br/>
Tutarli <br/>
Yol Yok <br/>

--

**Örnek 4:** <br/>
Matris Boyutu : 2 <br/>
Degerler : 5 5 2 2 <br/>

**Cikti :** <br/>
Tutarsiz Yeniden giris Yapin. <br/>
