<?php

/**
 * @file
 * Template for PDFs.
 */

?>

<!DOCTYPE html PUBLIC "-//W3C//DTD HTML+RDFa 1.1//EN">
<html lang="en" dir="ltr" version="HTML+RDFa 1.1" xmlns:xsd="http://www.w3.org/2001/XMLSchema#">
<head profile="http://www.w3.org/1999/xhtml/vocab">
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <style type="text/css">
    body {
  font-family: Arial, sans-serif;
  font-size: 16px;
}
.header {
  width: 100%;
  height: 100px;
}
.header img {
  width: 88px;
  position: absolute;
}
.text {
  position: absolute;
  top: 300px;
}
.invoice-header {
  font-size: 14px;
  color: #646464;
  text-align: right;
}
.invoice-footer {
  border-top: 1px solid #646464;
  width: 100%;
  font-size: 14px;
  color: #646464;
  text-align: center;
  padding-top: 4px;
}

.invoice-text {
  margin-top: 50px;
}

.customer .field-label,
.customer .field__label {
  display: none;
}
.customer .field-name-field-customer-lastname,
.customer .field--name-field-customer-lastname {
  display: none;
}

.invoice-number {
  position: absolute;
  top: 350px;
}
.order-id {
  position: absolute;
  top: 370px;
}
.invoice-header-date {
  margin-top: 25px;
  margin-left: 550px;
  text-align: right;
}
.line-items {
  margin-top: 200px;
}
.invoice-footer {
  position: absolute;
  bottom: 0;
}
.view-commerce-line-item-table table {
  width: 100%;
  line-height: 1.2em;
  border-collapse: collapse;
}
.view-commerce-line-item-table thead {
  border-bottom: 2px solid black;
}
.view-commerce-line-item-table th {
  text-align: right;
}
.view-commerce-line-item-table td {
  text-align: right;
  height: 30px;
}
.view-commerce-line-item-table .views-field-commerce-total {
  text-align: right;
  padding-right: 5px;
  width: 200px;
}
.view-commerce-line-item-table .views-field-line-item-title {
  text-align: left;
  width: 300px;
}

.order-total table {
  width: 100%;
  border-top: 2px solid black;
  font-weight: bold;
}
td.component-title {
  text-align: right;
}
td.component-total {
  text-align: right;
  width: 200px;
}

.contextual-links-wrapper {
  display: none;
}

.invoice-canceled .order-total table {
  border: 2px solid black;
  margin-top: 100px;
}
.invoice-header{font-size: 2em}

.invoice-number, .order-id, .invoice-footer {
  position: initial;
}
.invoice-footer {margin-top: 30px}
.invoice-header-date{text-align:left; margin:0;}
.line-items{margin-top: 50px;}
.invoice-text{margin-top: 50px;}

.customer{ margin:0;border: 0px solid red;}
.supplier {border: 0px solid red;float:right;}
table.customer-supplier td{vertical-align: top}
table.customer-supplier th {text-align: center; background: #eaeaea}
.line-items-view table{width: 100%; border: 1px solid grey;     border-collapse: collapse;}
.line-items-view table td, 
.line-items-view table th{ border: 1px solid grey; padding:5px; text-align: center;}
.line-items-view table td.views-align-right{text-align: right;}
div.order-totals{float: right;text-align: right;}
table.order-totals {margin-top: 10px;  border: 0px solid grey;     border-collapse: collapse;}
table.order-totals td, table.order-totals th{ border: 0px solid grey; text-align: right; padding-right: 5px;padding-left: 50px;}
.totals-wrapper td{text-align: right; padding:0} 
.important{color: red; font-weight: bold;}
.warning{font-size: 1.5em; color: red;text-align: center; margin: 30px 0; border-bottom: 2px solid red;}
  </style>
</head>
<body>

<div class="invoice-invoiced">
  <div class="header">
    <div class="invoice-header">
        <p><?php print render($trainer_invoice['trainer_full_name']); ?></p>
    </div>
  </div>

  <hr/>
  <?php 
  if ( $trainer_invoice['preview_mode']){
    echo "<div class=\"warning\">Atension! This is only a preview of the invoice! "
    . "<br>To create it click on Create invoise link from My invoices tab and specify a number and date</div>";
  }
  ?>
  <div class="invoice-number">Invoice # <?php print render($trainer_invoice['invoice_number']); ?></div>
  <div class="invoice-header-date">Date of issue: <?php print render($trainer_invoice['invoice_date_of_issue']); ?></div>
  <div class="invoice-header-date">Tax event date: <?php print render($trainer_invoice['tax_event_date']); ?></div>
  <div class="invoice-header-date">Due for payment not latter than: <?php print render($trainer_invoice['invoice_dueto_date']); ?></div>


  <table class="customer-supplier" width="100%">
      <tr>
          <td valign="top" width="50%"><div class="customer">
                <table  border="0" cellspacing="10">
                      <tr><th colspan="2">Customer</th></tr>
                      <tr>
                          <td> Name                         </td>
                          <td> Sqwirl IT Ltd</td>
                      </tr>
                      <tr>
                          <td> Address                         </td>
                          <td> 1421 Sofia, <br>23, Dimitar Hadjikotzev str.                         </td>
                      </tr>
                      <tr>
                          <td> VAT Number                        </td>
                          <td> BG201035369</td>
                      </tr>                      
                  </table> 
              </div></td>
          <td valign="top">  <div class="supplier">
                <table  border="0" cellspacing="10">
                      <tr><th colspan="2">Supplier</th></tr>
                      <tr>
                          <td> Name                         </td>
                          <td><?php print render($trainer_invoice['trainer_full_name']); ?></td>
                      </tr>
                      <tr>
                          <td> Address                         </td>
                          <td><?php print drupal_render($trainer_invoice['trainer_address']); ?>                          </td>

                      </tr>
                      <tr>
                          <td> VAT Number                        </td>
                          <td><?php print render($trainer_invoice['trainer_VAT']); ?></td>
                      </tr>                      
                  </table>
              </div></td>
      </tr>
  </table>
  

  <div class="line-items">
    <div class="line-items-view"><?php print render($trainer_invoice['li']); ?></div>
        <table class="totals-wrapper" width="100%" border="0">
            <tr>
                <td width="75%">&nbsp;</td>
                <td>
                  <table  class="order-totals" border="0" >
                        <tr>
                            <th> Total amaunt                        </th>
                            <th> <?php print render($trainer_invoice['invoice_total']); ?></th>
                        </tr>

                    </table>
                </td>
          </tr>
        </table>
  </div>

  <div class="invoice-text">Bank account details: <?php print render($trainer_invoice['trainer_bank_account_details']); ?>
      <br />BIC: <?php print render($trainer_invoice['trainer_BIC']); ?>
      <br />IBAN: <?php print render($trainer_invoice['trainer_IBAN']); ?>
  </div>
  <div class="invoice-footer"></div>
</div>

</body></html>
