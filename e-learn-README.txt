E_LEARN README NOTES


* trainers and regular users
	+ different registration forms and profiles

* user workflow
   + browse
   + buy - paypal
   + see Course
   + take Quiz
   + granted Certificate
   + invoice

* trainer workflow
   + create Course
   + create Quiz
   - edit/delete Course ???
   - see published PD for the Course
   - reports

* site admin workflow
   + approve trainers
   + manage taxonomy
   + reports

* course
   + add video field and player?
   + add images and make a slidehsow of them
   + grant access to Course after product that referensed it was bought
   + revoke access to Course after sertain period of time (48 hours for example, 5 min in development)

* quiz
   + quiz creation - clear most of fields in edit tab
   - style Certificate
   + questions browser - filter by current user


+ features
+ terms
- theme
+ search
+ multilanguage


TODO:
    
-remove manage fields link from admin/structure/taxonomy/tags for siteadmins
- create  a table to hold user -> course relationship with start access date and revoke access date. Add these 2 dates on /user/%/courses

Questions:
+ price of the Course
+ should trainer be able to edit own Course and Quiz to course
+ should trainer be able to delete own Course 
+ fields for user/trainer profiles



Install:

- mpdf lib for pdf generation
WD print_pdf: Failed to create directory                             [error]
"public://print_pdf/print_pdf_mpdf/ttfontdata" for print_pdf_mpdf.
WD print_pdf: Failed to create directory                             [error]
"public://print_pdf/print_pdf_mpdf/tmp" for print_pdf_mpdf.

public:// = sites/default/files



====================================================
1.  Цел – платформа където ще се качват лекции/курсове от регистрирани и одобрени „треньори“, което да бъде достъпно до регистрирани потребители срещу заплащане през интернет (PayPal и/или собствен виртуален ПОС терминал)
2.  Лекции/Курсове – текст и видео които могат да се разглеждат за определен период от време.
3.  Тест и Сертификат – След изтичане на времето за разглеждане на лекциите, те стават недостъпни и се появява възможност за Тест. Теста може да се проведе до 3 пъти. Ако теста е успешен се генерира сертификат за успешно преминаване на курса на името на потребителя.
4.  Общо съдържание на платформата – кои сме ние и какво предлагаме, категории курсове, кратко описание на отделните курсове, съдържание на курс.  
5.  Регистрация на потребители – регистрирани потребители могат да достъпват до пълната функционалност – съдържание на курс, тест и сертификат след заплащане.
6. Регистрация на треньори - регистрирани и одобрени от администратор на платформата треньори могат да качват курсове
7. Плащане – Стойността на курса се заплаща от Потребителя на Треньора и Собственика на платформата (СкуирълИТ) в съотношение 70% / 30% автоматично през PayPal .
8.  Модул справки – регистрирани потребители и треньори; брой продадени курсове и стойност на продажбите по треньори, потребители и общо за тях; разбивка на дяловете на продажби на курсове по Tреньори, Скуиръл ИТ и такси PayPal . Справките са за период, по календарни месеци за година.
9. Фактуриране от Скуиръл ИТ– автоматично се генерира и изпраща фактура на името на потребителя за 30% от цената на курса. Фактурите се съхраняват в меню фактури и могат да се сортират по потребители, треньори, дата и суми. 
Фактурите са два вида според издателя - (1) на Треньора към Скуиръл и на (2) на Скуиръл към Клиента. При покупка се генерират 2 бр. фактури - (1) за 70% минус разходите на PayPal и (2) за 100%. Когато има двама треньори по един курс - собственик и преводач - фактурите са три броя, 100% на Скуиръл към Клиента, 50% на Треньора-собственик към Скуиръл и 20% на Треньора-преводач към Скуиръл.


. Курсовете да бъдат достъпни за продажба за време, което се определя от треньора. 
. Времето за разлеждане на курса след покупка и преди теста се определя от треньора.
 В общата част да има място за кратки биографии на треньорите и препоръки от доволни клиенти (testimonials)
Курсовете да могат да се избират по категория, предмет, заглавие и език
======================================================

промени от 4.03.2016

+ Само фирми купуват
+ Активиране на курс - качване на списък с имейли, създаване на акунти, пращане на имейли + текст
Период за активиране на курса (примерно една година) - от купуване до активирането. След него няма да може да се активира купения курс.
+ Цена на курса 
	- базова - определя се от треньора  
	- цена по групи - до 10, до 25, до 50, do 100 - процент от базовата цена. Цената по групи е уникална за сайта.
+ Фирмата да може да вижда кои са регистрираните за курса и кой поне веднъж е вляззъл в курса. И крайния резултат от теста
- Фактурата към фирмата да е за 70% от стойността на поръчката
======================================================

		
+ 0. да се създадат таблиците (може и на ръка може и в модула)
+ 1. да се добави към поръчката лайн айтем с цената по групи
+ 2. при завършване на поръчка да се запише в таблицата course-instance  - id, date-bought, company_id, order_id, course_holder_id, date-activated
+ 3. Интерфейс за активиране на курс - списък с имейли и текст за писмото.
+ 3а.при активиране на курс: 
                   + да се запише в таблицата course-instance - date-activated
                   + да се запише в таблицата course-instance-enrolled - course_instance_id, course_holder_id, user_id, first_accessed, last_accessed,  score_1, score_2, score_3
                   + да се проверят имейлите от списъка и ако няма акаунти да се създадат
                   + за всеки акаунт от списъка да се добави ред в таблицата course-instance-enrolled
                   + за всеки акаунт в таблицата да се дадат права за course, course_holder, quiz (може да се използва сегашния rule)
- 4. при завършване на тест да се запише в таблицата course-instance-enrolled - score 1,2,3
+ 5. view activity page - first accessed, best result - a link to best result - ??? access to results????
================================
+ да се махне My orders таба от акаунта на юзер
+ да се махне Courses I bought таба от акаунта на юзер
+ да се обави Му ordered courses таб за треньор в който да cа всички покупки на негови курсове
+ elearn_menu_alter -         //allow company that enrolled a user to see his quiz results




