Commerce 3-D Secure API
=======================

* For standalone 3-D Secure providers:

After you have installed this module you must edit your Commerce payment method
instance to utilize a 3-D Secure provider.

On the payment method settings form there will be a new section titled
'3-D Secure Settings'. If you have installed a module that implements this API
it will be displayed in the 3-D Secure Provider select box. Select the provider
you wish to use and click Save. Re-edit the payment method and your MPI settings
will now be displayed below the select box. Click Save to finish setting up
your 3-D Secure provider.

After doing the above you need to ensure that your payment method can receive
the authentication data from this module. This can happen either as part of the
payment module or as an extra helper module.

* For integrated 3-D Secure providers:

Your payment method will use only the 3-D Secure step in the checkout process.
This does not require any setting up in the back end.
