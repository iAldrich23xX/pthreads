/*
  +----------------------------------------------------------------------+
  | pthreads                                                             |
  +----------------------------------------------------------------------+
  | Copyright (c) Joe Watkins 2012 - 2015                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Joe Watkins <krakjoe@php.net>                                |
  +----------------------------------------------------------------------+
 */
#ifndef HAVE_PTHREADS_OBJECT_H
#define HAVE_PTHREADS_OBJECT_H

#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#ifndef HAVE_PTHREADS_H
#	include <src/pthreads.h>
#endif

/* {{{ object creation and destruction */
zend_object* pthreads_threaded_ctor(zend_class_entry *entry);
zend_object* pthreads_worker_ctor(zend_class_entry *entry);
zend_object* pthreads_thread_ctor(zend_class_entry *entry);
void        pthreads_base_free(zend_object *object);
/* }}} */

/* {{{ worker management */
uint32_t pthreads_worker_pop(pthreads_object_t* thread, zval *work);
uint32_t pthreads_worker_push(pthreads_object_t* thread, zval *work);
uint32_t pthreads_worker_collect(pthreads_object_t* thread, pthreads_call_t *call);
uint32_t pthreads_worker_length(pthreads_object_t* thread);
/* }}} */

/* {{{ MISC */
void pthreads_current_thread(zval *return_value);
/* }}} */

/* {{{ start/join */
zend_bool pthreads_start(pthreads_object_t* thread);
zend_bool pthreads_join(pthreads_object_t* thread);
/* }}} */

/* {{{ */
int pthreads_connect(pthreads_object_t* source, pthreads_object_t* destination); /* }}} */

/* {{{ */
#ifndef HAVE_PTHREADS_HANDLERS_H
#	include <src/handlers.h>
#endif /* }}} */

#endif /* HAVE_PTHREADS_OBJECT_H */
