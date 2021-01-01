--TEST--
Test error cases when creating a socket on non-win32
--CREDITS--
Copied from php/php-src and adjusted, originally created by 
Russell Flynn <russ@redpill-linpro.com>
#PHPTestFest2009 Norway 2009-06-09 \o/
--SKIPIF--
<?php
if (substr(PHP_OS, 0, 3) == 'WIN') {
	die('skip.. Not valid for Windows');
}
--INI--
error_reporting=E_ALL
display_errors=1
--FILE--
<?php
  // Test with no arguments
  try{
    $server = new Socket();
  }catch(\ArgumentCountError $e){
    echo $e->getMessage() . PHP_EOL;
  }

  try{
    // Test with less arguments than required
    $server = new Socket(\Socket::SOCK_STREAM, getprotobyname('tcp'));
  }catch(\ArgumentCountError $e){
    echo $e->getMessage() . PHP_EOL;
  }
  
  try {
    // Test with non integer parameters
    $server = new Socket(array(), 1, 1);
  } catch(Throwable $throwable) {
    var_dump($throwable->getMessage());
  }

  try {
    // Test with unknown domain
    $server = new Socket(\Socket::AF_INET + 1000, \Socket::SOCK_STREAM, 0);
  } catch(Throwable $throwable) {
    var_dump($throwable->getMessage());
  }
  
?>
--EXPECTF--
Socket::__construct() expects exactly 3 parameters, 0 given
Socket::__construct() expects exactly 3 parameters, 2 given
string(%d) "Argument 1 passed to Socket::__construct() must be of the type %s, array given"
string(%d) "Unable to create socket (%d): Address family not supported by protocol"
