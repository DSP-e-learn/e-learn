<html>
<form action="http://elearn.perla/commerce_paypal/ipn/paypal_wps%7Ccommerce_payment_paypal_wps" method="post">
<input type="text" value = "dddd" name="name" />
<button type="submit" name ="submit" />
</form>
<?php
$fp = stream_socket_client("ssl://www.paypal.com:443", $errno, $errstr, 30);
if (!$fp) {
    echo "ddddddddddddddddddddddddddddddddd". "$errstr ($errno)<br />\n";
} else {var_dump($fp); exit;
    fwrite($fp, "GET / HTTP/1.0\r\nHost: www.example.com\r\nAccept: */*\r\n\r\n");
    while (!feof($fp)) {
        echo fgets($fp, 1024);
    }
    fclose($fp);
}
?>

</html>

