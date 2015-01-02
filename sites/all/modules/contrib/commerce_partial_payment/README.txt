Allows users to make partial payments when checking out with a commerce order.

This project is sponsored by AllPlayers.com (http://www.allplayers.com).

Configuration
=============
After enabling commerce_partial_payment, give appropriate roles the "make
partial payment" permission at
/admin/people/permissions#module-commerce_partial_payment. Users with this
permission will be able to specify an amount they would like to pay at checkout.

Admins can already add partial payments to an order at
/admin/commerce/orders/%order_id/payment.
