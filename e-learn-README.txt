E_LEARN README NOTES


* trainers and regular users
	+ different registration forms and profiles

* user workflow
   + browse
   - buy - paypal
   + see Course
   + take Quiz
   + granted Certificate
   - invoice

* trainer workflow
   + create Course
   + create Quiz
   - edit/delete Course
   - see published PD for the Course
   - reports

* site admin workflow
   + approve trainers
   - reports

* course
   - add video field and player?
   - add images and make a slidehsow of them
   + grant access to Course after product that referensed it was bought
   + revoke access to Course after sertain period of time (48 hours for example, 5 min in development)

* quiz
   - quiz creation - clear most of fields in edit tab
   - style Certificate


+ features
+ terms
- theme
- search
- multilanguage


TODO:
    


Questions:
- price of the Course
- 75% to pass the quiz?
- shuld quiz be available after the access to Course has been revoked
- should trainer be able to edit own Course and Quiz to course
- should trainer be able to delete own Course 
- fields for user/trainer profiles



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
======================================================

