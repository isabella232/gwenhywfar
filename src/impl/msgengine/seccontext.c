/***************************************************************************
 $RCSfile$
                             -------------------
    cvs         : $Id$
    begin       : Wed Nov 19 2003
    copyright   : (C) 2003 by Martin Preuss
    email       : martin@libchipcard.de

 ***************************************************************************
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Lesser General Public            *
 *   License as published by the Free Software Foundation; either          *
 *   version 2.1 of the License, or (at your option) any later version.    *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston,                 *
 *   MA  02111-1307  USA                                                   *
 *                                                                         *
 ***************************************************************************/


#ifdef HAVE_CONFIG_H
# include <config.h>
#endif


#include "seccontext_p.h"
#include <gwenhyfwar/misc.h>
#include <gwenhyfwar/debug.h>
#include <gwenhyfwar/text.h>
#include <stdlib.h>
#include <string.h>




GWEN_SECCTX *GWEN_SecContext_new(const char *localName,
                                 const char *remoteName){
  GWEN_SECCTX *sc;

  GWEN_NEW_OBJECT(GWEN_SECCTX, sc);
  if (localName)
    sc->localName=strdup(localName);
  if (remoteName)
    sc->remoteName=strdup(remoteName);
  sc->localSignSeq=1;
  sc->remoteSignSeq=0;
  return sc;
}



void GWEN_SecContext_free(GWEN_SECCTX *sc){
  if (sc) {
    if (sc->data && sc->freeDataFn)
      sc->freeDataFn(sc);
    free(sc->localName);
    free(sc->remoteName);
    free(sc);
  }
}



void GWEN_SecContext_SetPrepareCtxFn(GWEN_SECCTX *sc,
                                     GWEN_SECCTX_PREPARECTX_FN fn){
  assert(sc);
  sc->prepareFn=fn;
}



void GWEN_SecContext_SetSignFn(GWEN_SECCTX *sc,
                               GWEN_SECCTX_SIGN_FN fn){
  assert(sc);
  sc->signFn=fn;
}



void GWEN_SecContext_SetVerifyFn(GWEN_SECCTX *sc,
                                 GWEN_SECCTX_VERIFY_FN fn){
  assert(sc);
  sc->verifyFn=fn;
}



void GWEN_SecContext_SetEncryptFn(GWEN_SECCTX *sc,
                                  GWEN_SECCTX_ENCRYPT_FN fn){
  assert(sc);
  sc->encryptFn=fn;
}



void GWEN_SecContext_SetDecrpytFn(GWEN_SECCTX *sc,
                                  GWEN_SECCTX_DECRYPT_FN fn){
  assert(sc);
  sc->decryptFn=fn;
}



void GWEN_SecContext_SetFreeDataFn(GWEN_SECCTX *sc,
                                   GWEN_SECCTX_FREEDATA_FN fn){
  assert(sc);
  sc->freeDataFn=fn;
}



const char *GWEN_SecContext_GetLocalName(GWEN_SECCTX *sc){
  assert(sc);
  return sc->localName;
}



void GWEN_SecContext_SetLocalName(GWEN_SECCTX *sc,
                                  const char *s){
  assert(sc);
  assert(s);
  free(sc->localName);
  sc->localName=strdup(s);
}



const char *GWEN_SecContext_GetRemoteName(GWEN_SECCTX *sc){
  assert(sc);
  return sc->remoteName;
}



void GWEN_SecContext_SetRemoteName(GWEN_SECCTX *sc,
                                   const char *s){
  assert(sc);
  assert(s);
  free(sc->remoteName);
  sc->remoteName=strdup(s);
}



unsigned int GWEN_SecContext_GetLocalSignSeq(GWEN_SECCTX *sc){
  assert(sc);
  return sc->localSignSeq;
}



void GWEN_SecContext_SetLocalSignSeq(GWEN_SECCTX *sc,
                                     unsigned int i){
  assert(sc);
  if (sc->localSignSeq>i) {
    DBG_WARN(0,
             "Local signature sequence is higher (%d>%d), not adjusting",
             sc->localSignSeq, i);
  }
  else {
    sc->localSignSeq=i;
  }
}



unsigned int GWEN_SecContext_NextLocalSignSeq(GWEN_SECCTX *sc){
  assert(sc);
  return sc->localSignSeq++;
}



unsigned int GWEN_SecContext_GetRemoteSignSeq(GWEN_SECCTX *sc){
  assert(sc);
  return sc->remoteSignSeq;
}



void GWEN_SecContext_SetRemoteSignSeq(GWEN_SECCTX *sc,
                                      unsigned int i){
  assert(sc);
  if (sc->remoteSignSeq>i) {
    DBG_WARN(0,
             "Remote signature sequence is higher (%d>%d), not adjusting",
             sc->remoteSignSeq, i);
  }
  else {
    sc->remoteSignSeq=i;
  }
}



void *GWEN_SecContext_GetData(GWEN_SECCTX *sc){
  assert(sc);
  return sc->data;
}



void GWEN_SecContext_SetData(GWEN_SECCTX *sc,
                             void *d){
  assert(sc);
  if (sc->data && sc->freeDataFn)
    sc->freeDataFn(sc);
  sc->data=d;
}



int GWEN_SecContext_PrepareContext(GWEN_SECCTX *sc,
                                   GWEN_HBCICRYPTOCONTEXT *ctx,
                                   int crypt){
  assert(sc);
  assert(ctx);
  DBG_NOTICE(0, "Preparing context for service \"%s\"",
             GWEN_HBCICryptoContext_GetServiceCode(ctx));
  if (sc->prepareFn)
    return sc->prepareFn(sc, ctx, crypt);
  DBG_ERROR(0, "Prepare function not set.");
  return -1;
}



int GWEN_SecContext_Sign(GWEN_SECCTX *sc,
                         GWEN_BUFFER *msgbuf,
                         GWEN_BUFFER *signbuf,
                         GWEN_HBCICRYPTOCONTEXT *ctx){
  assert(sc);
  if (sc->signFn)
    return sc->signFn(sc, msgbuf, signbuf, ctx);
  DBG_ERROR(0, "Sign function not set.");
  return -1;
}



int GWEN_SecContext_Verify(GWEN_SECCTX *sc,
                           GWEN_BUFFER *msgbuf,
                           GWEN_BUFFER *signbuf,
                           GWEN_HBCICRYPTOCONTEXT *ctx){
  assert(sc);
  if (sc->verifyFn)
    return sc->verifyFn(sc, msgbuf, signbuf, ctx);
  DBG_ERROR(0, "Verify function not set.");
  return -1;
}



int GWEN_SecContext_Encrypt(GWEN_SECCTX *sc,
                            GWEN_BUFFER *msgbuf,
                            GWEN_BUFFER *cryptbuf,
                            GWEN_HBCICRYPTOCONTEXT *ctx){
  assert(sc);
  if (sc->encryptFn)
    return sc->encryptFn(sc, msgbuf, cryptbuf, ctx);
  DBG_ERROR(0, "Encrypt function not set.");
  return -1;
}



int GWEN_SecContext_Decrypt(GWEN_SECCTX *sc,
                            GWEN_BUFFER *msgbuf,
                            GWEN_BUFFER *decryptbuf,
                            GWEN_HBCICRYPTOCONTEXT *ctx){
  assert(sc);
  if (sc->decryptFn)
    return sc->decryptFn(sc, msgbuf, decryptbuf, ctx);
  DBG_ERROR(0, "Decrypt function not set.");
  return -1;
}




/*
 * This code has been taken from OpenHBCI (rsakey.cpp, written by Fabian
 * Kaiser)
 */
unsigned char GWEN_SecContext_permutate(unsigned char input) {
  unsigned char leftNibble;
  unsigned char rightNibble;
  static const unsigned char lookUp[2][16] =
    {{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
    {14,3,5,8,9,4,2,15,0,13,11,6,7,10,12,1}};

  rightNibble = input & 15;
  leftNibble = input & 240;
  leftNibble = leftNibble / 16;
  rightNibble = lookUp[1][rightNibble];
  leftNibble = lookUp[1][leftNibble];
  leftNibble = leftNibble * 16;

  return leftNibble + rightNibble;
}



/*
 * The original code (in C++) has been written by Fabian Kaiser for OpenHBCI
 * (file rsakey.cpp). Moved to C by me (Martin Preuss)
 */
int GWEN_SecContext_PaddWithISO9796(GWEN_BUFFER *src) {
  unsigned char *p;
  unsigned int l;
  unsigned int i;
  unsigned char buffer[GWEN_SECCONTEXT_KEYSIZE];
  unsigned char hash[20];
  unsigned char c;

  p=(unsigned char*)GWEN_Buffer_GetStart(src);
  l=GWEN_Buffer_GetUsedBytes(src);
  memmove(hash, p, l);

  /* src+src+src */
  if (GWEN_Buffer_AppendBytes(src, (const char*)hash, l)) {
    DBG_INFO(0, "here");
    return -1;
  }

  if (GWEN_Buffer_AppendBytes(src, (const char*)hash, l)) {
    DBG_INFO(0, "here");
    return -1;
  }

  /* src=src(20,40) */
  if (GWEN_Buffer_Crop(src, 20, 40)) {
    DBG_INFO(0, "here");
    return -1;
  }

  memset(buffer, 0, sizeof(buffer));

  /* append redundancy */
  p=(unsigned char*)GWEN_Buffer_GetStart(src);
  for (i=0; i<=47; i++) {
    int j1, j2, j3;

    j1=1 + sizeof(buffer) - (2*i);
    j2=40-i;
    j3=sizeof(buffer) - (2*i);

    if (j1>=0 && j1<(int)sizeof(buffer) && j2>=0) {
      buffer[j1]=p[j2];
    }
    if (j3>=0 && j3<(int)sizeof(buffer) && j2>=0) {
      buffer[j3]=GWEN_SecContext_permutate(p[j2]);
    }
  } /* for */

  /* copy last 16 bytes to the beginning */
  memmove(buffer, buffer+(sizeof(buffer)-16), 16);

  p=buffer;
  /* finish */
  c=p[sizeof(buffer)-1];
  c = (c & 15) * 16;
  c += 6;
  p[sizeof(buffer)-1]=c;
  p[0] = p[0] & 127;
  p[0] = p[0] | 64;
  p[sizeof(buffer) - 40] = p[sizeof(buffer) - 40] ^ 1;

  GWEN_Buffer_Reset(src);
  if (GWEN_Buffer_AppendBytes(src, (const char*)buffer, sizeof(buffer))) {
    DBG_INFO(0, "here");
    return -1;
  }

  return 0;
}




int GWEN_SecContext_PaddWithANSIX9_23(GWEN_BUFFER *src) {
  unsigned char paddLength;
  unsigned int i;

  paddLength=8-(GWEN_Buffer_GetUsedBytes(src) % 8);
  for (i=0; i<paddLength; i++)
    GWEN_Buffer_AppendByte(src, paddLength);
  return 0;
}



int GWEN_SecContext_UnpaddWithANSIX9_23(GWEN_BUFFER *src) {
  const char *p;
  unsigned int lastpos;
  unsigned char paddLength;

  lastpos=GWEN_Buffer_GetUsedBytes(src);
  if (lastpos<8) {
    DBG_ERROR(0, "Buffer too small");
    return -1;
  }
  lastpos--;

  p=GWEN_Buffer_GetStart(src)+lastpos;
  paddLength=*p;
  if (paddLength<1 || paddLength>8) {
    DBG_ERROR(0, "Invalid padding (%d bytes ?)", paddLength);
    return -1;
  }
  GWEN_Buffer_SetUsedBytes(src, GWEN_Buffer_GetUsedBytes(src)-paddLength);
  GWEN_Buffer_SetPos(src, lastpos-paddLength);
  return 0;
}










GWEN_SECCTX_MANAGER *GWEN_SecContextMgr_new(const char *serviceCode){
  GWEN_SECCTX_MANAGER *scm;

  assert(serviceCode);
  GWEN_NEW_OBJECT(GWEN_SECCTX_MANAGER, scm);
  scm->contextList=GWEN_List_new();
  scm->serviceCode=strdup(serviceCode);
  return scm;
}



void GWEN_SecContextMgr_free(GWEN_SECCTX_MANAGER *scm){
  if (scm) {
    if (scm->data && scm->freeDataFn)
      scm->freeDataFn(scm);
    GWEN_List_free(scm->contextList);
    free(scm->serviceCode);
    free(scm);
  }
}



void GWEN_SecContextMgr_SetGetFn(GWEN_SECCTX_MANAGER *scm,
                                 GWEN_SECCTXMGR_GETCONTEXT_FN fn){
  assert(scm);
  scm->getContextFn=fn;
}



void GWEN_SecContextMgr_SetAddFn(GWEN_SECCTX_MANAGER *scm,
                                 GWEN_SECCTXMGR_ADDCONTEXT_FN fn){
  assert(scm);
  scm->addContextFn=fn;
}



void GWEN_SecContextMgr_SetDelFn(GWEN_SECCTX_MANAGER *scm,
                                 GWEN_SECCTXMGR_DELCONTEXT_FN fn){
  assert(scm);
  scm->delContextFn=fn;
}



void GWEN_SecContextMgr_SetFreeDataFn(GWEN_SECCTX_MANAGER *scm,
                                      GWEN_SECCTXMGR_FREEDATA_FN fn){
  assert(scm);
  scm->freeDataFn=fn;
}



void *GWEN_SecContextMgr_GetData(GWEN_SECCTX_MANAGER *scm){
  assert(scm);
  return scm->data;
}



void GWEN_SecContextMgr_SetData(GWEN_SECCTX_MANAGER *scm,
                                void *d){
  assert(scm);
  if (scm->data && scm->freeDataFn)
    scm->freeDataFn(scm);
  scm->data=d;
}



GWEN_SECCTX *GWEN_SecContextMgr_GetContext(GWEN_SECCTX_MANAGER *scm,
                                           const char *localName,
                                           const char *remoteName){
  GWEN_LIST_ITERATOR *it;

  assert(scm);
  DBG_WARN(0, "Looking for context \"%s:%s\"", localName, remoteName);
  it=GWEN_List_First(scm->contextList);
  if (it) {
    GWEN_SECCTX *sc;

    sc=(GWEN_SECCTX*)GWEN_ListIterator_Data(it);
    while(sc) {
      if ((GWEN_Text_Compare(sc->localName, localName, 1)==0) &&
          (GWEN_Text_Compare(sc->remoteName, remoteName, 1)==0)){
        GWEN_ListIterator_free(it);
        return sc;
      }
      sc=(GWEN_SECCTX*)GWEN_ListIterator_Next(it);
    } /* while */
  }
  GWEN_ListIterator_free(it);

  if (scm->getContextFn) {
    DBG_INFO(0, "Context \"%s:%s\" not already known, trying function",
             localName, remoteName);
    return scm->getContextFn(scm, localName, remoteName);
  }
  DBG_INFO(0, "Context \"%s:%s\" not found.", localName, remoteName);
  return 0;
}



int GWEN_SecContextMgr_AddContext(GWEN_SECCTX_MANAGER *scm,
                                  GWEN_SECCTX *sc){
  assert(scm);
  if (scm->addContextFn) {
    if (scm->addContextFn(scm, sc)) {
      DBG_INFO(0, "here");
      return -1;
    }
  }
  DBG_INFO(0, "Pushing back context");
  GWEN_List_PushBack(scm->contextList, sc);
  return 0;
}



int GWEN_SecContextMgr_DelContext(GWEN_SECCTX_MANAGER *scm,
                                  GWEN_SECCTX *sc){
  assert(scm);
  if (scm->delContextFn)
    return scm->delContextFn(scm, sc);
  DBG_ERROR(0, "Function not implemented.");
  return -1;
}



const char *GWEN_SecContext_GetServiceCode(GWEN_SECCTX_MANAGER *scm){
  assert(scm);
  return scm->serviceCode;
}















