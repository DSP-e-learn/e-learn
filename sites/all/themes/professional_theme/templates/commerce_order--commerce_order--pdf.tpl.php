<?php

/**
 * @file
 * Customized
 * Template for invoiced orders to the Companies - buyers.
 */

?>
<?php print render($content['li']); ?>
<div class="invoice-invoiced">
  <div class="header">
    <!--<img src="<?php print $content['invoice_logo']['#value']; ?>"/> -->
    <div class="invoice-header">
        <p><?php print render($content['invoice_header']); ?></p>
    </div>
  </div>

  <hr/>
  <div class="invoice-number"><?php print render($content['order_number']); ?></div>
  <div class="invoice-header-date">Date of issue: <?php print render($content['invoice_header_date']); ?></div>
  <div class="invoice-header-date">Tax event date: <?php print render($content['invoice_header_date']); ?></div>

  <table class="customer-supplier" width="100%">
      <tr>
          <td valign="top" width="50%"><div class="customer">
                  <table  border="0" cellspacing="10">
                      <tr><th colspan="2">Customer</th></tr>
                      <tr>
                          <td> Name                         </td>
                          <td><?php print render($content['company_full_name']); ?></td>

                      </tr>
                      <tr>
                          <td> Address                         </td>
                          <td><?php print drupal_render($content['company_address']); ?>                          </td>

                      </tr>
                      <tr>
                          <td> Registration number                         </td>
                          <td>                          </td>

                      </tr> 
                      <tr>
                          <td> VAT Number                        </td>
                          <td><?php print render($content['company_VAT']); ?></td>

                      </tr>                      
                  </table>
            <?php //print render($content['commerce_customer_billing']); ?></div></td>
          <td valign="top">  <div class="supplier">
                <table  border="0" cellspacing="10">
                      <tr><th colspan="2">Supplier</th></tr>
                      <tr>
                          <td> Name                         </td>
                          <td> Sqwirl IT Ltd</td>

                      </tr>
                      <tr>
                          <td> Address                         </td>
                          <td> 1421 Sofia, <br>23, Dimitar Hadjikotzev str.                         </td>

                      </tr>
                      <tr>
                          <td> Bulstat                         </td>
                          <td> 201035369                        </td>

                      </tr> 
                      <tr>
                          <td> VAT Number                        </td>
                          <td> BG201035369</td>

                      </tr>                      
                  </table>
              </div></td>
      </tr>
  </table>
  

 <!-- <div class="order-id"><?php print render($content['order_id']); ?></div>-->

  <div class="line-items">
    <div class="line-items-view"><?php print render($content['commerce_line_items']); ?></div>
    <!--<div class="order-total"><?php //print render($content['commerce_order_total']); ?></div>-->
    <div class="order-totals">    
    <table  class="order-totals" border="0" >
          <tr>
              <td> Tax base                         </td>
              <td> <?php print render($content['commerce_order_total']); ?></td>

          </tr>
           <tr>
              <td> VAT rate                          </td>
              <td> 0.00</td>
          </tr>
          <tr>
              <th> Total amaunt                        </th>
              <th> <?php print render($content['commerce_order_total']); ?></th>

          </tr>

      </table>
    </div>
  </div>
  <div class="invoice-text"><?php print render($content['invoice_text']); ?></div>

  <div class="invoice-footer"><?php print render($content['invoice_footer']); ?></div>
</div>
