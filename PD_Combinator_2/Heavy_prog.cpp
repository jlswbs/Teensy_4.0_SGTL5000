/**
 * Copyright (c) 2024 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#include "Heavy_prog.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_prog *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_prog_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_prog));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_prog(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_prog_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_prog));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_prog(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_prog_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_prog();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_prog::Heavy_prog(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_init(&sPhasor_gNoeGD7y, sampleRate);
  numBytes += sLine_init(&sLine_INqueJBO);
  numBytes += sPhasor_init(&sPhasor_CPwgIEw7, sampleRate);
  numBytes += sLine_init(&sLine_qwgTv6Iy);
  numBytes += sPhasor_k_init(&sPhasor_yzmlOvph, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_g92OtMmv, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_ISnsxs6B);
  numBytes += sPhasor_init(&sPhasor_SsDKYspL, sampleRate);
  numBytes += sPhasor_init(&sPhasor_R2rjPAPz, sampleRate);
  numBytes += sPhasor_init(&sPhasor_OLrMGZuH, sampleRate);
  numBytes += sLine_init(&sLine_9EJR0fMQ);
  numBytes += sPhasor_k_init(&sPhasor_wD7kWVbt, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_YRindpgD, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_cVWspHuH);
  numBytes += sPhasor_init(&sPhasor_GLHcENgr, sampleRate);
  numBytes += sLine_init(&sLine_b06M6EJs);
  numBytes += sTabhead_init(&sTabhead_jbxl0hw2, &hTable_xmQkqrQL);
  numBytes += sTabread_init(&sTabread_4zUTVKiE, &hTable_xmQkqrQL, false);
  numBytes += sTabread_init(&sTabread_ip2JD7XQ, &hTable_xmQkqrQL, false);
  numBytes += sLine_init(&sLine_ULnYA8c4);
  numBytes += sLine_init(&sLine_ZPCAg4tK);
  numBytes += sTabhead_init(&sTabhead_7TJCgywj, &hTable_Jov25Euz);
  numBytes += sTabread_init(&sTabread_qPPSvO4u, &hTable_Jov25Euz, false);
  numBytes += sTabread_init(&sTabread_AnhwPVjn, &hTable_Jov25Euz, false);
  numBytes += sLine_init(&sLine_OLNqf6rw);
  numBytes += sTabwrite_init(&sTabwrite_qe8csanJ, &hTable_Jov25Euz);
  numBytes += sTabwrite_init(&sTabwrite_bMOTC4o6, &hTable_xmQkqrQL);
  numBytes += sDel1_init(&sDel1_ayHaDPeW);
  numBytes += sSamphold_init(&sSamphold_2zzi3J0r);
  numBytes += sRPole_init(&sRPole_uxrw0ldi);
  numBytes += sLine_init(&sLine_FEy95cyc);
  numBytes += cVar_init_f(&cVar_aiRCK1oD, 0.0f);
  numBytes += cVar_init_f(&cVar_Yh7ZaLaW, 1.0f);
  numBytes += cVar_init_f(&cVar_2pl4jBpU, 0.0f);
  numBytes += cRandom_init(&cRandom_4ZgURvdc, 968849140);
  numBytes += cSlice_init(&cSlice_vrK9TF39, 1, 1);
  numBytes += cPack_init(&cPack_UQTwpzzV, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_zvGpWtLp, 4, 1);
  numBytes += cSlice_init(&cSlice_82PSRnaT, 3, 1);
  numBytes += cSlice_init(&cSlice_g5VEvdj4, 2, 1);
  numBytes += cSlice_init(&cSlice_NVL5jLGD, 1, 1);
  numBytes += cSlice_init(&cSlice_6FofwjpR, 0, 1);
  numBytes += sVarf_init(&sVarf_GlloTte0, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_1vx1lJNn, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Wh6MsQGV, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_CJN8HIfH, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_5JG3lF6I, 0.0f);
  numBytes += cDelay_init(this, &cDelay_CwoPwYzq, 0.0f);
  numBytes += cVar_init_f(&cVar_mkywTWXq, 240.0f);
  numBytes += cBinop_init(&cBinop_PTeaD87O, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_098MrJol, 0.0f);
  numBytes += cVar_init_f(&cVar_LpTlsNAz, 480.0f);
  numBytes += cBinop_init(&cBinop_AoRQ5956, 0.0f); // __mul
  numBytes += cRandom_init(&cRandom_hBewCX0x, -394352233);
  numBytes += cSlice_init(&cSlice_0G6qF7OG, 1, 1);
  numBytes += cPack_init(&cPack_KLY3LGks, 2, 0.0f, 0.0f);
  numBytes += cSlice_init(&cSlice_QxKagxVX, 4, 1);
  numBytes += cSlice_init(&cSlice_Qkv5ThHK, 3, 1);
  numBytes += cSlice_init(&cSlice_ndlY3XOw, 2, 1);
  numBytes += cSlice_init(&cSlice_JCoG3y5p, 1, 1);
  numBytes += cSlice_init(&cSlice_NVeozXoq, 0, 1);
  numBytes += sVarf_init(&sVarf_Eo5uVgAQ, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_7MkhI79o, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Jz6YwMZ9, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_LXPyvtOw, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_otRIPRcb, 0.0f);
  numBytes += cVar_init_f(&cVar_OnbjfxGY, 0.0f);
  numBytes += cVar_init_f(&cVar_nutjQ3Ru, 0.0f);
  numBytes += cVar_init_f(&cVar_jVl6QLbI, 0.0f);
  numBytes += cRandom_init(&cRandom_RfJDcNjZ, 1606956019);
  numBytes += cSlice_init(&cSlice_6Bu9xezm, 1, 1);
  numBytes += sVari_init(&sVari_Y3QmRdRe, 0, 0, false);
  numBytes += cVar_init_f(&cVar_t3poRff3, 22050.0f);
  numBytes += cBinop_init(&cBinop_h7jlsLxy, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Lv1AzgcS, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9RhbTFla, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_6QPphwpk, 0.0f);
  numBytes += cRandom_init(&cRandom_g1rW638j, 189357899);
  numBytes += cSlice_init(&cSlice_7Spm2iIS, 1, 1);
  numBytes += cRandom_init(&cRandom_gcUPhuNH, 805487359);
  numBytes += cSlice_init(&cSlice_g7Nn7iLx, 1, 1);
  numBytes += cRandom_init(&cRandom_k2ro9kEb, 2120922008);
  numBytes += cSlice_init(&cSlice_DKTKYBLN, 1, 1);
  numBytes += cVar_init_f(&cVar_h72jDZ7T, 27.0f);
  numBytes += cVar_init_f(&cVar_DTIgZLXy, 32.0f);
  numBytes += cVar_init_f(&cVar_Bk1dABXY, 15.0f);
  numBytes += cVar_init_f(&cVar_eRiL2yWF, 110.0f);
  numBytes += cBinop_init(&cBinop_sSD5V6Wy, 29.0f); // __div
  numBytes += sVarf_init(&sVarf_F5s5mKsE, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_w8TNEhMs, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_4s2HcG77, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_iYjx5fiq, 4.0f);
  numBytes += cVar_init_f(&cVar_MwEqr9aS, 30.0f);
  numBytes += cVar_init_f(&cVar_dFZeiE3V, 250.0f);
  numBytes += cPack_init(&cPack_1Nod8XHy, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_tuBwxxga, 500.0f);
  numBytes += cVar_init_f(&cVar_ysupMWVd, 60.0f);
  numBytes += cSlice_init(&cSlice_uxHPuSYv, 2, 1);
  numBytes += cSlice_init(&cSlice_KmnIo8w1, 1, 1);
  numBytes += cSlice_init(&cSlice_5uoj88TA, 0, 1);
  numBytes += cSlice_init(&cSlice_qCzaca8K, 1, -1);
  numBytes += cDelay_init(this, &cDelay_nKlF56qA, 0.0f);
  numBytes += cDelay_init(this, &cDelay_Srv0mtAA, 0.0f);
  numBytes += cIf_init(&cIf_kcFUHI7p, false);
  numBytes += cSlice_init(&cSlice_Ny7ODDq3, 1, -1);
  numBytes += cPack_init(&cPack_eKCdba70, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_joS7FMdj, 1.0f, 0.0f, false);
  numBytes += cPack_init(&cPack_N1n2CkNa, 2, 0.0f, 0.0f);
  numBytes += cPack_init(&cPack_4H1VbQv5, 2, 0.0f, 0.0f);
  numBytes += cVar_init_s(&cVar_6glDRNGD, "del-1098-inputdelay");
  numBytes += sVarf_init(&sVarf_FJgiRSCt, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Po7eldEU, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_R0sGSf7M, 0.0f, 0.0f, false);
  numBytes += cVar_init_s(&cVar_VqfTk6jb, "del-1098-outputdelay");
  numBytes += sVarf_init(&sVarf_nwfdR6Mg, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_VXGWDsPI, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_SmpXAesD, 0.0f, 0.0f, false);
  numBytes += cDelay_init(this, &cDelay_EiSzSbBK, 0.0f);
  numBytes += cDelay_init(this, &cDelay_PLsdDGp0, 0.0f);
  numBytes += hTable_init(&hTable_Jov25Euz, 256);
  numBytes += cDelay_init(this, &cDelay_juNN3NNb, 0.0f);
  numBytes += cDelay_init(this, &cDelay_eMse7GWe, 0.0f);
  numBytes += hTable_init(&hTable_xmQkqrQL, 256);
  numBytes += cBinop_init(&cBinop_S2FP6PG1, 1.0f); // __pow
  numBytes += sVarf_init(&sVarf_jsJlLOQh, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_EllOqpYi, 220.0f);
  numBytes += cVar_init_f(&cVar_5qPxTDML, 8.0f);
  numBytes += cPack_init(&cPack_Yfp80uRY, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_QWs5OS1T, 30.0f);
  numBytes += cVar_init_f(&cVar_qBmmDtsc, 50.0f);
  numBytes += cVar_init_f(&cVar_Mq5Fi3Fh, 500.0f);
  numBytes += cVar_init_f(&cVar_vywe2R7d, 440.0f);
  numBytes += cSlice_init(&cSlice_5gI4bLcd, 2, 1);
  numBytes += cSlice_init(&cSlice_mw1Ervf5, 1, 1);
  numBytes += cSlice_init(&cSlice_sFXfrfpu, 0, 1);
  numBytes += cSlice_init(&cSlice_u11miyXO, 1, -1);
  numBytes += cDelay_init(this, &cDelay_q1eoZw9j, 0.0f);
  numBytes += cDelay_init(this, &cDelay_9ZFZGq0Q, 0.0f);
  numBytes += cIf_init(&cIf_YBWhmpSZ, false);
  numBytes += cSlice_init(&cSlice_WG2PqURk, 1, -1);
  numBytes += cPack_init(&cPack_2LD1IgzH, 2, 0.0f, 0.0f);
  numBytes += sVarf_init(&sVarf_wd5Y9tHI, 2.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_reah5MgV, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Q1f0npz2, 1.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_prog::~Heavy_prog() {
  cPack_free(&cPack_UQTwpzzV);
  cPack_free(&cPack_KLY3LGks);
  cPack_free(&cPack_1Nod8XHy);
  cPack_free(&cPack_eKCdba70);
  cPack_free(&cPack_N1n2CkNa);
  cPack_free(&cPack_4H1VbQv5);
  hTable_free(&hTable_Jov25Euz);
  hTable_free(&hTable_xmQkqrQL);
  cPack_free(&cPack_Yfp80uRY);
  cPack_free(&cPack_2LD1IgzH);
}

HvTable *Heavy_prog::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0xBD4F5B80: return &hTable_Jov25Euz; // del-1098-outputdelay
    case 0xA1463E8F: return &hTable_xmQkqrQL; // del-1098-inputdelay
    default: return nullptr;
  }
}

void Heavy_prog::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_DTwMSfIL_sendMessage);
      break;
    }
    case 0xF7AB77BA: { // dur
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7Gnvxz6y_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_prog::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 0;
}



/*
 * Send Function Implementations
 */


void Heavy_prog::cVar_aiRCK1oD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_4bYH7yiC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cVar_Yh7ZaLaW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_6T3PWVUJ_sendMessage);
  cSwitchcase_4DrVFaIt_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_eOdck9JL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_6T3PWVUJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Yh7ZaLaW, 1, m, &cVar_Yh7ZaLaW_sendMessage);
}

void Heavy_prog::cVar_2pl4jBpU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xJCB7PT4_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_taThuE4j_sendMessage);
}

void Heavy_prog::cSwitchcase_oUK1aQIu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_vrK9TF39, 0, m, &cSlice_vrK9TF39_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_4ZgURvdc, 0, m, &cRandom_4ZgURvdc_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_D05BVZuL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ZsaIafBp_sendMessage);
}

void Heavy_prog::cUnop_ZsaIafBp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_otRIPRcb, 0, m, &cVar_otRIPRcb_sendMessage);
}

void Heavy_prog::cRandom_4ZgURvdc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_D05BVZuL_sendMessage);
}

void Heavy_prog::cSlice_vrK9TF39_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_4ZgURvdc, 1, m, &cRandom_4ZgURvdc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cPack_UQTwpzzV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_R6OSAxJx_sendMessage(_c, 0, m);
}

void Heavy_prog::cSlice_zvGpWtLp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_GlloTte0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_82PSRnaT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_CJN8HIfH, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_g5VEvdj4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_Wh6MsQGV, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_NVL5jLGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_YRindpgD, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_6FofwjpR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_wD7kWVbt, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_RqbmmAsF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3xYR0mjn_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_3xYR0mjn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bkrbrdYb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WlQpd8A6_sendMessage);
}

void Heavy_prog::cCast_bkrbrdYb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_WlQpd8A6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rWPuBdWg_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_4LzXIU3B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1vx1lJNn, HV_BINOP_MULTIPLY, 0, m, &cBinop_1vx1lJNn_sendMessage);
}

void Heavy_prog::cCast_49uQdjEj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_UQTwpzzV, 0, m, &cPack_UQTwpzzV_sendMessage);
}

void Heavy_prog::cMsg_rWPuBdWg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4LzXIU3B_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_49uQdjEj_sendMessage);
}

void Heavy_prog::cBinop_1vx1lJNn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_UQTwpzzV, 1, m, &cPack_UQTwpzzV_sendMessage);
}

void Heavy_prog::cBinop_G9sESCL5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1vx1lJNn, HV_BINOP_MULTIPLY, 1, m, &cBinop_1vx1lJNn_sendMessage);
}

void Heavy_prog::cMsg_fND9TiaK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 600.0f, 0, m, &cBinop_G9sESCL5_sendMessage);
}

void Heavy_prog::cMsg_R6OSAxJx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_cVWspHuH, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  sLine_onMessage(_c, &Context(_c)->sLine_cVWspHuH, 0, m, NULL);
}

void Heavy_prog::cMsg_ZXO3U6By_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(5);
  msg_init(m, 5, msg_getTimestamp(n));
  msg_setFloat(m, 0, 748.031f);
  msg_setFloat(m, 1, 1023.62f);
  msg_setFloat(m, 2, 0.173228f);
  msg_setFloat(m, 3, 1968.5f);
  msg_setFloat(m, 4, 9259.84f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_zvGpWtLp, 0, m, &cSlice_zvGpWtLp_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_82PSRnaT, 0, m, &cSlice_82PSRnaT_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_g5VEvdj4, 0, m, &cSlice_g5VEvdj4_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_NVL5jLGD, 0, m, &cSlice_NVL5jLGD_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_6FofwjpR, 0, m, &cSlice_6FofwjpR_sendMessage);
}

void Heavy_prog::cVar_5JG3lF6I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SW9uKNGL_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TtGPo869_sendMessage);
}

void Heavy_prog::cSwitchcase_4DrVFaIt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_cvXWpo3V_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_cvXWpo3V_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5R2J2JPC_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_CwoPwYzq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CwoPwYzq, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CwoPwYzq, 0, m, &cDelay_CwoPwYzq_sendMessage);
  cSwitchcase_oUK1aQIu_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_GodFSekb_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_M8cpJm7L_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_5R2J2JPC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cvXWpo3V_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CwoPwYzq, 0, m, &cDelay_CwoPwYzq_sendMessage);
  cSwitchcase_oUK1aQIu_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_GodFSekb_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_M8cpJm7L_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_J8zuecjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NNl2jeBG_sendMessage);
}

void Heavy_prog::cSystem_NNl2jeBG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_xMU2aa3c_sendMessage);
}

void Heavy_prog::cVar_mkywTWXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PTeaD87O, HV_BINOP_MULTIPLY, 0, m, &cBinop_PTeaD87O_sendMessage);
}

void Heavy_prog::cMsg_cvXWpo3V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_CwoPwYzq, 0, m, &cDelay_CwoPwYzq_sendMessage);
}

void Heavy_prog::cBinop_rispCD3H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CwoPwYzq, 2, m, &cDelay_CwoPwYzq_sendMessage);
}

void Heavy_prog::cBinop_xMU2aa3c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PTeaD87O, HV_BINOP_MULTIPLY, 1, m, &cBinop_PTeaD87O_sendMessage);
}

void Heavy_prog::cBinop_PTeaD87O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_rispCD3H_sendMessage);
}

void Heavy_prog::cSwitchcase_eOdck9JL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cMsg_sv4uTztQ_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_sv4uTztQ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Z5i9I8xY_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cDelay_098MrJol_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_098MrJol, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_098MrJol, 0, m, &cDelay_098MrJol_sendMessage);
  cSwitchcase_dzZfk3eb_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_bprVS7Xl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_Z5i9I8xY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sv4uTztQ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_098MrJol, 0, m, &cDelay_098MrJol_sendMessage);
  cSwitchcase_dzZfk3eb_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_bprVS7Xl_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_x8VvW1Cx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OEkt7vA0_sendMessage);
}

void Heavy_prog::cSystem_OEkt7vA0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_UmDJnpws_sendMessage);
}

void Heavy_prog::cVar_LpTlsNAz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AoRQ5956, HV_BINOP_MULTIPLY, 0, m, &cBinop_AoRQ5956_sendMessage);
}

void Heavy_prog::cMsg_sv4uTztQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_098MrJol, 0, m, &cDelay_098MrJol_sendMessage);
}

void Heavy_prog::cBinop_XxM9sjEc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_098MrJol, 2, m, &cDelay_098MrJol_sendMessage);
}

void Heavy_prog::cBinop_UmDJnpws_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AoRQ5956, HV_BINOP_MULTIPLY, 1, m, &cBinop_AoRQ5956_sendMessage);
}

void Heavy_prog::cBinop_AoRQ5956_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_XxM9sjEc_sendMessage);
}

void Heavy_prog::cSwitchcase_dzZfk3eb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_0G6qF7OG, 0, m, &cSlice_0G6qF7OG_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hBewCX0x, 0, m, &cRandom_hBewCX0x_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_DKOI8Zbf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_nP21HRNf_sendMessage);
}

void Heavy_prog::cUnop_nP21HRNf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_GXFsseLj_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 80.0f, 0, m, &cBinop_j3ijTEpo_sendMessage);
}

void Heavy_prog::cRandom_hBewCX0x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_DKOI8Zbf_sendMessage);
}

void Heavy_prog::cSlice_0G6qF7OG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_hBewCX0x, 1, m, &cRandom_hBewCX0x_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cPack_KLY3LGks_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YxW06bU2_sendMessage(_c, 0, m);
}

void Heavy_prog::cSlice_QxKagxVX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_Eo5uVgAQ, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_Qkv5ThHK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_LXPyvtOw, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_ndlY3XOw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sVarf_onMessage(_c, &Context(_c)->sVarf_Jz6YwMZ9, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_JCoG3y5p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_g92OtMmv, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_NVeozXoq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_yzmlOvph, 0, m);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_54xvQSZI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uBLLjFhs_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_uBLLjFhs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QyHMQ2Xs_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fYLh7G1D_sendMessage);
}

void Heavy_prog::cCast_QyHMQ2Xs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_prog::cCast_fYLh7G1D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ji6fkGOk_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_4XvlD1I0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7MkhI79o, HV_BINOP_MULTIPLY, 0, m, &cBinop_7MkhI79o_sendMessage);
}

void Heavy_prog::cCast_n57LjzfT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KLY3LGks, 0, m, &cPack_KLY3LGks_sendMessage);
}

void Heavy_prog::cMsg_Ji6fkGOk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4XvlD1I0_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_n57LjzfT_sendMessage);
}

void Heavy_prog::cBinop_7MkhI79o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_KLY3LGks, 1, m, &cPack_KLY3LGks_sendMessage);
}

void Heavy_prog::cBinop_kwqVT4si_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7MkhI79o, HV_BINOP_MULTIPLY, 1, m, &cBinop_7MkhI79o_sendMessage);
}

void Heavy_prog::cMsg_CYBsaUyk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.1f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 600.0f, 0, m, &cBinop_kwqVT4si_sendMessage);
}

void Heavy_prog::cMsg_YxW06bU2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 0.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ISnsxs6B, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  sLine_onMessage(_c, &Context(_c)->sLine_ISnsxs6B, 0, m, NULL);
}

void Heavy_prog::cMsg_q5pt7pvL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(5);
  msg_init(m, 5, msg_getTimestamp(n));
  msg_setFloat(m, 0, 748.031f);
  msg_setFloat(m, 1, 1023.62f);
  msg_setFloat(m, 2, 0.173228f);
  msg_setFloat(m, 3, 1968.5f);
  msg_setFloat(m, 4, 9259.84f);
  cSlice_onMessage(_c, &Context(_c)->cSlice_QxKagxVX, 0, m, &cSlice_QxKagxVX_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_Qkv5ThHK, 0, m, &cSlice_Qkv5ThHK_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_ndlY3XOw, 0, m, &cSlice_ndlY3XOw_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_JCoG3y5p, 0, m, &cSlice_JCoG3y5p_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_NVeozXoq, 0, m, &cSlice_NVeozXoq_sendMessage);
}

void Heavy_prog::cVar_otRIPRcb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_RqbmmAsF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cVar_OnbjfxGY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_54xvQSZI_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cVar_nutjQ3Ru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1000.0f, 0, m, &cBinop_JPwK6lRr_sendMessage);
}

void Heavy_prog::cVar_jVl6QLbI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 0.999f, 0, m, &cBinop_iKcTlPki_sendMessage);
}

void Heavy_prog::cSwitchcase_LSJI0p9M_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_6Bu9xezm, 0, m, &cSlice_6Bu9xezm_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RfJDcNjZ, 0, m, &cRandom_RfJDcNjZ_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_hNEulwuh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_9lPFIcMs_sendMessage);
}

void Heavy_prog::cUnop_9lPFIcMs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vV5SEkXI_sendMessage(_c, 0, m);
}

void Heavy_prog::cRandom_RfJDcNjZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_hNEulwuh_sendMessage);
}

void Heavy_prog::cSlice_6Bu9xezm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RfJDcNjZ, 1, m, &cRandom_RfJDcNjZ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_vV5SEkXI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_Y3QmRdRe, m);
}

void Heavy_prog::cVar_t3poRff3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h7jlsLxy, HV_BINOP_MULTIPLY, 0, m, &cBinop_h7jlsLxy_sendMessage);
}

void Heavy_prog::cMsg_zLXzGPqp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_X8VPuPuB_sendMessage);
}

void Heavy_prog::cSystem_X8VPuPuB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cmnqwQLI_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_h7jlsLxy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_N5yxTYbU_sendMessage);
}

void Heavy_prog::cBinop_NxguxrRH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_h7jlsLxy, HV_BINOP_MULTIPLY, 1, m, &cBinop_h7jlsLxy_sendMessage);
}

void Heavy_prog::cMsg_cmnqwQLI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_NxguxrRH_sendMessage);
}

void Heavy_prog::cBinop_N5yxTYbU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_KrF8HKwF_sendMessage);
}

void Heavy_prog::cBinop_KrF8HKwF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_zcq74E7o_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_9RhbTFla, m);
}

void Heavy_prog::cBinop_zcq74E7o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Lv1AzgcS, m);
}

void Heavy_prog::cVar_6QPphwpk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_t3poRff3, 0, m, &cVar_t3poRff3_sendMessage);
}

void Heavy_prog::cSwitchcase_GodFSekb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_7Spm2iIS, 0, m, &cSlice_7Spm2iIS_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_g1rW638j, 0, m, &cRandom_g1rW638j_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_U4E9GPsR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Wfylgilh_sendMessage);
}

void Heavy_prog::cUnop_Wfylgilh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OnbjfxGY, 0, m, &cVar_OnbjfxGY_sendMessage);
}

void Heavy_prog::cRandom_g1rW638j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10.0f, 0, m, &cBinop_U4E9GPsR_sendMessage);
}

void Heavy_prog::cSlice_7Spm2iIS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_g1rW638j, 1, m, &cRandom_g1rW638j_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_bprVS7Xl_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_g7Nn7iLx, 0, m, &cSlice_g7Nn7iLx_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_gcUPhuNH, 0, m, &cRandom_gcUPhuNH_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_SkToAz6k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_7XWecGHm_sendMessage);
}

void Heavy_prog::cUnop_7XWecGHm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aiRCK1oD, 0, m, &cVar_aiRCK1oD_sendMessage);
}

void Heavy_prog::cRandom_gcUPhuNH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 4.0f, 0, m, &cBinop_SkToAz6k_sendMessage);
}

void Heavy_prog::cSlice_g7Nn7iLx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_gcUPhuNH, 1, m, &cRandom_gcUPhuNH_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_M8cpJm7L_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_DKTKYBLN, 0, m, &cSlice_DKTKYBLN_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_k2ro9kEb, 0, m, &cRandom_k2ro9kEb_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cBinop_vVGhwjnk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_sLSTULwU_sendMessage);
}

void Heavy_prog::cUnop_sLSTULwU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_2pl4jBpU, 0, m, &cVar_2pl4jBpU_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_Xxx8qrTU_sendMessage);
}

void Heavy_prog::cRandom_k2ro9kEb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 80.0f, 0, m, &cBinop_vVGhwjnk_sendMessage);
}

void Heavy_prog::cSlice_DKTKYBLN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_k2ro9kEb, 1, m, &cRandom_k2ro9kEb_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_4bYH7yiC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_bjLwEH9L_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5wztGdB3_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vTcSO1GS_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cCast_bjLwEH9L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_71Y1z5oG_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Yvlh3erB_sendMessage);
}

void Heavy_prog::cCast_5wztGdB3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9dzDUlXT_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ojJA8Bkt_sendMessage);
}

void Heavy_prog::cCast_vTcSO1GS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DlLR2X2l_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BtGPhqys_sendMessage);
}

void Heavy_prog::cVar_h72jDZ7T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sSD5V6Wy, HV_BINOP_DIVIDE, 1, m, &cBinop_sSD5V6Wy_sendMessage);
}

void Heavy_prog::cVar_DTIgZLXy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sSD5V6Wy, HV_BINOP_DIVIDE, 1, m, &cBinop_sSD5V6Wy_sendMessage);
}

void Heavy_prog::cVar_Bk1dABXY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sSD5V6Wy, HV_BINOP_DIVIDE, 1, m, &cBinop_sSD5V6Wy_sendMessage);
}

void Heavy_prog::cVar_eRiL2yWF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_A3RLwPHc_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_dApQoou2_sendMessage);
}

void Heavy_prog::cCast_dApQoou2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sSD5V6Wy, HV_BINOP_DIVIDE, 0, m, &cBinop_sSD5V6Wy_sendMessage);
}

void Heavy_prog::cCast_A3RLwPHc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KxBxiXsX_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_sSD5V6Wy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_F5s5mKsE, m);
}

void Heavy_prog::cCast_BtGPhqys_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eRiL2yWF, 0, m, &cVar_eRiL2yWF_sendMessage);
}

void Heavy_prog::cCast_DlLR2X2l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Bk1dABXY, 0, m, &cVar_Bk1dABXY_sendMessage);
}

void Heavy_prog::cCast_9dzDUlXT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DTIgZLXy, 0, m, &cVar_DTIgZLXy_sendMessage);
}

void Heavy_prog::cCast_ojJA8Bkt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eRiL2yWF, 0, m, &cVar_eRiL2yWF_sendMessage);
}

void Heavy_prog::cCast_71Y1z5oG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_h72jDZ7T, 0, m, &cVar_h72jDZ7T_sendMessage);
}

void Heavy_prog::cCast_Yvlh3erB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eRiL2yWF, 0, m, &cVar_eRiL2yWF_sendMessage);
}

void Heavy_prog::cMsg_KxBxiXsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_FEy95cyc, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 0);
  sLine_onMessage(_c, &Context(_c)->sLine_FEy95cyc, 0, m, NULL);
}

void Heavy_prog::cBinop_r1X9R6Iq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_4s2HcG77, m);
}

void Heavy_prog::cBinop_e6Tn0GU6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_7rNNT0un_sendMessage);
}

void Heavy_prog::cBinop_7rNNT0un_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_w8TNEhMs, HV_BINOP_POW, 1, m, &cBinop_w8TNEhMs_sendMessage);
  cMsg_T7cXIqMb_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_w8TNEhMs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_r1X9R6Iq_sendMessage);
}

void Heavy_prog::cMsg_T7cXIqMb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_w8TNEhMs, HV_BINOP_POW, 0, m, &cBinop_w8TNEhMs_sendMessage);
}

void Heavy_prog::cBinop_OIoTrfnH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -10.0f, 0, m, &cBinop_JwQKCIR6_sendMessage);
}

void Heavy_prog::cBinop_JwQKCIR6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_joS7FMdj, m);
}

void Heavy_prog::cBinop_LBpp8JLi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -10.0f, 0, m, &cBinop_9p3Xd09a_sendMessage);
}

void Heavy_prog::cBinop_9p3Xd09a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xoBllgxi_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_iYjx5fiq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_OIoTrfnH_sendMessage);
}

void Heavy_prog::cVar_MwEqr9aS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_LBpp8JLi_sendMessage);
}

void Heavy_prog::cVar_dFZeiE3V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1Nod8XHy, 0, m, &cPack_1Nod8XHy_sendMessage);
}

void Heavy_prog::cPack_1Nod8XHy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_3ezHxxDS_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_tuBwxxga_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1Nod8XHy, 2, m, &cPack_1Nod8XHy_sendMessage);
}

void Heavy_prog::cVar_ysupMWVd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_1Nod8XHy, 1, m, &cPack_1Nod8XHy_sendMessage);
}

void Heavy_prog::cSlice_uxHPuSYv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_nKlF56qA, 1, m, &cDelay_nKlF56qA_sendMessage);
      cDelay_onMessage(_c, &Context(_c)->cDelay_Srv0mtAA, 1, m, &cDelay_Srv0mtAA_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_KmnIo8w1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vIqIyuB2_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EDysp0eQ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_5uoj88TA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_hg4XhQY4_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_rjybilXn_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_qCzaca8K, 0, m, &cSlice_qCzaca8K_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NCrzSwAh_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_uxHPuSYv, 0, m, &cSlice_uxHPuSYv_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_KmnIo8w1, 0, m, &cSlice_KmnIo8w1_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_5uoj88TA, 0, m, &cSlice_5uoj88TA_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_qCzaca8K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tyAMXxmW_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yvYfVLPg_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tyAMXxmW_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_yvYfVLPg_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cDelay_nKlF56qA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nKlF56qA, m);
  cPack_onMessage(_c, &Context(_c)->cPack_eKCdba70, 0, m, &cPack_eKCdba70_sendMessage);
  cMsg_7pRq9alZ_sendMessage(_c, 0, m);
}

void Heavy_prog::cDelay_Srv0mtAA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Srv0mtAA, m);
  cPack_onMessage(_c, &Context(_c)->cPack_eKCdba70, 1, m, &cPack_eKCdba70_sendMessage);
}

void Heavy_prog::cIf_kcFUHI7p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_Srv0mtAA, 0, m, &cDelay_Srv0mtAA_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_hg4XhQY4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cSlice_onMessage(_c, &Context(_c)->cSlice_Ny7ODDq3, 0, m, &cSlice_Ny7ODDq3_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_AvgM8uc8_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NFUlCTez_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_Ny7ODDq3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_qNpttpd5_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_qNpttpd5_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_7pRq9alZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_kcFUHI7p, 1, m, &cIf_kcFUHI7p_sendMessage);
}

void Heavy_prog::cMsg_kheggnw3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_kcFUHI7p, 1, m, &cIf_kcFUHI7p_sendMessage);
}

void Heavy_prog::cCast_AvgM8uc8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_kcFUHI7p, 0, m, &cIf_kcFUHI7p_sendMessage);
}

void Heavy_prog::cCast_NFUlCTez_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nKlF56qA, 0, m, &cDelay_nKlF56qA_sendMessage);
}

void Heavy_prog::cCast_EDysp0eQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kheggnw3_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_vIqIyuB2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Srv0mtAA, 0, m, &cDelay_Srv0mtAA_sendMessage);
}

void Heavy_prog::cMsg_qNpttpd5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Srv0mtAA, 0, m, &cDelay_Srv0mtAA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nKlF56qA, 0, m, &cDelay_nKlF56qA_sendMessage);
}

void Heavy_prog::cPack_eKCdba70_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_qwgTv6Iy, 0, m, NULL);
}

void Heavy_prog::cCast_NCrzSwAh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_748jSgcN_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_748jSgcN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cDelay_onMessage(_c, &Context(_c)->cDelay_nKlF56qA, 1, m, &cDelay_nKlF56qA_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Srv0mtAA, 1, m, &cDelay_Srv0mtAA_sendMessage);
}

void Heavy_prog::cMsg_p9TcWUzc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  sLine_onMessage(_c, &Context(_c)->sLine_qwgTv6Iy, 0, m, NULL);
}

void Heavy_prog::cCast_tyAMXxmW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rQUfWe5j_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_yvYfVLPg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_p9TcWUzc_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_rQUfWe5j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cSwitchcase_hg4XhQY4_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cMsg_xoBllgxi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 50.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_INqueJBO, 0, m, NULL);
}

void Heavy_prog::cCast_xJCB7PT4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vFErfk8W_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HEiJNswg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pITKsaW4_sendMessage);
}

void Heavy_prog::cCast_taThuE4j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_e6Tn0GU6_sendMessage);
}

void Heavy_prog::cCast_HEiJNswg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ysupMWVd, 0, m, &cVar_ysupMWVd_sendMessage);
}

void Heavy_prog::cCast_vFErfk8W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tuBwxxga, 0, m, &cVar_tuBwxxga_sendMessage);
}

void Heavy_prog::cCast_pITKsaW4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dFZeiE3V, 0, m, &cVar_dFZeiE3V_sendMessage);
}

void Heavy_prog::cMsg_3ezHxxDS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_rjybilXn_onMessage(_c, NULL, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  msg_setElementToFrom(m, 2, n, 2);
  cSwitchcase_rjybilXn_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cPack_N1n2CkNa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_b06M6EJs, 0, m, NULL);
}

void Heavy_prog::cPack_4H1VbQv5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_ZPCAg4tK, 0, m, NULL);
}

void Heavy_prog::cMsg_FNIfuuk1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Mb4EvbKU_sendMessage);
}

void Heavy_prog::cSystem_Mb4EvbKU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_qKnL2005_sendMessage);
}

void Heavy_prog::cVar_6glDRNGD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mzJ9XLhq_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_GV4flLW8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_u01OKzZj_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_FJgiRSCt, m);
}

void Heavy_prog::cBinop_qKnL2005_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Po7eldEU, m);
}

void Heavy_prog::cMsg_mzJ9XLhq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GV4flLW8_sendMessage);
}

void Heavy_prog::cBinop_u01OKzZj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_R0sGSf7M, m);
}

void Heavy_prog::cMsg_5w8tYmy4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_S1nL0bMN_sendMessage);
}

void Heavy_prog::cSystem_S1nL0bMN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_AFC2ZIAj_sendMessage);
}

void Heavy_prog::cVar_VqfTk6jb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_d9PYKZpu_sendMessage(_c, 0, m);
}

void Heavy_prog::cSystem_YGlsqLmT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_eojmD9rk_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_nwfdR6Mg, m);
}

void Heavy_prog::cBinop_AFC2ZIAj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_VXGWDsPI, m);
}

void Heavy_prog::cMsg_d9PYKZpu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "size");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YGlsqLmT_sendMessage);
}

void Heavy_prog::cBinop_eojmD9rk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_SmpXAesD, m);
}

void Heavy_prog::cBinop_iKcTlPki_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_Ij0yeJtj_sendMessage);
}

void Heavy_prog::cBinop_Ij0yeJtj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_EhvtblXy_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_s8O3cVoG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_AUQau87V_sendMessage);
}

void Heavy_prog::cBinop_AUQau87V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_UBlffBWT_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_JPwK6lRr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_W0w9ZnSH_sendMessage);
}

void Heavy_prog::cBinop_W0w9ZnSH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TepkTFd9_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_UghXGZpI_sendMessage);
}

void Heavy_prog::cMsg_YqOnEL9n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_AXEt3Jug_sendMessage);
}

void Heavy_prog::cSystem_AXEt3Jug_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_EvAPuHzV_sendMessage);
}

void Heavy_prog::cDelay_EiSzSbBK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_EiSzSbBK, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PLsdDGp0, 0, m, &cDelay_PLsdDGp0_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EiSzSbBK, 0, m, &cDelay_EiSzSbBK_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_qe8csanJ, 1, m, NULL);
}

void Heavy_prog::cDelay_PLsdDGp0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PLsdDGp0, m);
  cMsg_gPLdNlOt_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_9oNnlIoT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_jquMpcI5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_ibXJkbG1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0sn39kJR_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_Jov25Euz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_szqOz9q9_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_EiSzSbBK, 2, m, &cDelay_EiSzSbBK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mTtx6Ka3_sendMessage);
}

void Heavy_prog::cMsg_0sn39kJR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_Jov25Euz, 0, m, &hTable_Jov25Euz_sendMessage);
}

void Heavy_prog::cBinop_EvAPuHzV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_ibXJkbG1_sendMessage);
}

void Heavy_prog::cMsg_gPLdNlOt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_Jov25Euz, 0, m, &hTable_Jov25Euz_sendMessage);
}

void Heavy_prog::cCast_mTtx6Ka3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_EiSzSbBK, 0, m, &cDelay_EiSzSbBK_sendMessage);
}

void Heavy_prog::cMsg_szqOz9q9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_PLsdDGp0, 2, m, &cDelay_PLsdDGp0_sendMessage);
}

void Heavy_prog::cMsg_jquMpcI5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_qe8csanJ, 1, m, NULL);
}

void Heavy_prog::cMsg_FEBo2Yri_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_a8t8muQR_sendMessage);
}

void Heavy_prog::cSystem_a8t8muQR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_RLWnH31p_sendMessage);
}

void Heavy_prog::cDelay_juNN3NNb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_juNN3NNb, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_eMse7GWe, 0, m, &cDelay_eMse7GWe_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_juNN3NNb, 0, m, &cDelay_juNN3NNb_sendMessage);
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_bMOTC4o6, 1, m, NULL);
}

void Heavy_prog::cDelay_eMse7GWe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_eMse7GWe, m);
  cMsg_KQn4A1DW_sendMessage(_c, 0, m);
}

void Heavy_prog::cSwitchcase_5dxa58Cs_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cMsg_G86vPzcj_sendMessage(_c, 0, m);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_prog::cBinop_WpoKdTCG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dYyND5N7_sendMessage(_c, 0, m);
}

void Heavy_prog::hTable_xmQkqrQL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yq5cEsRY_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_juNN3NNb, 2, m, &cDelay_juNN3NNb_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7o6XpGXJ_sendMessage);
}

void Heavy_prog::cMsg_dYyND5N7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "resize");
  msg_setElementToFrom(m, 1, n, 0);
  hTable_onMessage(_c, &Context(_c)->hTable_xmQkqrQL, 0, m, &hTable_xmQkqrQL_sendMessage);
}

void Heavy_prog::cBinop_RLWnH31p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 500.0f, 0, m, &cBinop_WpoKdTCG_sendMessage);
}

void Heavy_prog::cMsg_KQn4A1DW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "mirror");
  hTable_onMessage(_c, &Context(_c)->hTable_xmQkqrQL, 0, m, &hTable_xmQkqrQL_sendMessage);
}

void Heavy_prog::cCast_7o6XpGXJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_juNN3NNb, 0, m, &cDelay_juNN3NNb_sendMessage);
}

void Heavy_prog::cMsg_yq5cEsRY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0,  static_cast<float>(HV_N_SIMD));
  cDelay_onMessage(_c, &Context(_c)->cDelay_eMse7GWe, 2, m, &cDelay_eMse7GWe_sendMessage);
}

void Heavy_prog::cMsg_G86vPzcj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  sTabwrite_onMessage(_c, &Context(_c)->sTabwrite_bMOTC4o6, 1, m, NULL);
}

void Heavy_prog::cMsg_UBlffBWT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_OLNqf6rw, 0, m, NULL);
}

void Heavy_prog::cMsg_EhvtblXy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 10.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ULnYA8c4, 0, m, NULL);
}

void Heavy_prog::cCast_UghXGZpI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_N1n2CkNa, 1, m, &cPack_N1n2CkNa_sendMessage);
}

void Heavy_prog::cCast_TepkTFd9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_4H1VbQv5, 1, m, &cPack_4H1VbQv5_sendMessage);
}

void Heavy_prog::cBinop_l0RdqRrD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_4H1VbQv5, 0, m, &cPack_4H1VbQv5_sendMessage);
}

void Heavy_prog::cBinop_93B45Qgw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_N1n2CkNa, 0, m, &cPack_N1n2CkNa_sendMessage);
}

void Heavy_prog::cMsg_1wG5V4WJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 250.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 500.0f, 0, m, &cBinop_93B45Qgw_sendMessage);
}

void Heavy_prog::cMsg_WOPDsI1b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 250.0f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 500.0f, 0, m, &cBinop_l0RdqRrD_sendMessage);
}

void Heavy_prog::cMsg_DKKkeCNS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.9f);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 0.999f, 0, m, &cBinop_s8O3cVoG_sendMessage);
}

void Heavy_prog::cBinop_gz0rqwrY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jsJlLOQh, m);
}

void Heavy_prog::cBinop_U3XCOUBP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_6Z3bBouH_sendMessage);
}

void Heavy_prog::cBinop_6Z3bBouH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_S2FP6PG1, HV_BINOP_POW, 1, m, &cBinop_S2FP6PG1_sendMessage);
  cMsg_Dfu4PLzf_sendMessage(_c, 0, m);
}

void Heavy_prog::cBinop_S2FP6PG1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_gz0rqwrY_sendMessage);
}

void Heavy_prog::cMsg_Dfu4PLzf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_S2FP6PG1, HV_BINOP_POW, 0, m, &cBinop_S2FP6PG1_sendMessage);
}

void Heavy_prog::cBinop_oB2zxYOt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -10.0f, 0, m, &cBinop_DuVwESAm_sendMessage);
}

void Heavy_prog::cBinop_DuVwESAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Q1f0npz2, m);
}

void Heavy_prog::cBinop_nMbLbKCw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, -10.0f, 0, m, &cBinop_YwK2VTe5_sendMessage);
}

void Heavy_prog::cBinop_YwK2VTe5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wd5Y9tHI, m);
}

void Heavy_prog::cVar_EllOqpYi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_oB2zxYOt_sendMessage);
}

void Heavy_prog::cVar_5qPxTDML_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_nMbLbKCw_sendMessage);
}

void Heavy_prog::cPack_Yfp80uRY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YdKWnsWd_sendMessage(_c, 0, m);
}

void Heavy_prog::cVar_QWs5OS1T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Yfp80uRY, 2, m, &cPack_Yfp80uRY_sendMessage);
}

void Heavy_prog::cVar_qBmmDtsc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Yfp80uRY, 1, m, &cPack_Yfp80uRY_sendMessage);
}

void Heavy_prog::cVar_Mq5Fi3Fh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Yfp80uRY, 0, m, &cPack_Yfp80uRY_sendMessage);
}

void Heavy_prog::cVar_vywe2R7d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 10.0f, 0, m, &cBinop_e7uLgPjr_sendMessage);
}

void Heavy_prog::cBinop_e7uLgPjr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_PwmdIoto_sendMessage);
}

void Heavy_prog::cBinop_PwmdIoto_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_reah5MgV, m);
}

void Heavy_prog::cSlice_5gI4bLcd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_q1eoZw9j, 1, m, &cDelay_q1eoZw9j_sendMessage);
      cDelay_onMessage(_c, &Context(_c)->cDelay_9ZFZGq0Q, 1, m, &cDelay_9ZFZGq0Q_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_mw1Ervf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_XvtfFIR4_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WdEuSaDR_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSlice_sFXfrfpu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_hSubSJBr_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_tjlGOmkh_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_u11miyXO, 0, m, &cSlice_u11miyXO_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oI4uIjNf_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_5gI4bLcd, 0, m, &cSlice_5gI4bLcd_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_mw1Ervf5, 0, m, &cSlice_mw1Ervf5_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_sFXfrfpu, 0, m, &cSlice_sFXfrfpu_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_u11miyXO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LUpn9HNW_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_itsEQ3eR_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LUpn9HNW_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_itsEQ3eR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cDelay_q1eoZw9j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_q1eoZw9j, m);
  cPack_onMessage(_c, &Context(_c)->cPack_2LD1IgzH, 0, m, &cPack_2LD1IgzH_sendMessage);
  cMsg_QzGltapG_sendMessage(_c, 0, m);
}

void Heavy_prog::cDelay_9ZFZGq0Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9ZFZGq0Q, m);
  cPack_onMessage(_c, &Context(_c)->cPack_2LD1IgzH, 1, m, &cPack_2LD1IgzH_sendMessage);
}

void Heavy_prog::cIf_YBWhmpSZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cDelay_onMessage(_c, &Context(_c)->cDelay_9ZFZGq0Q, 0, m, &cDelay_9ZFZGq0Q_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cSwitchcase_hSubSJBr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x47BE8354: { // "clear"
      cSlice_onMessage(_c, &Context(_c)->cSlice_WG2PqURk, 0, m, &cSlice_WG2PqURk_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RiMII6VF_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lGnBmfgb_sendMessage);
      break;
    }
  }
}

void Heavy_prog::cSlice_WG2PqURk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Uoo8i25Q_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_Uoo8i25Q_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_prog::cMsg_QzGltapG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_YBWhmpSZ, 1, m, &cIf_YBWhmpSZ_sendMessage);
}

void Heavy_prog::cMsg_KlvMXGs5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_YBWhmpSZ, 1, m, &cIf_YBWhmpSZ_sendMessage);
}

void Heavy_prog::cCast_lGnBmfgb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_q1eoZw9j, 0, m, &cDelay_q1eoZw9j_sendMessage);
}

void Heavy_prog::cCast_RiMII6VF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_YBWhmpSZ, 0, m, &cIf_YBWhmpSZ_sendMessage);
}

void Heavy_prog::cCast_WdEuSaDR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KlvMXGs5_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_XvtfFIR4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9ZFZGq0Q, 0, m, &cDelay_9ZFZGq0Q_sendMessage);
}

void Heavy_prog::cMsg_Uoo8i25Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_9ZFZGq0Q, 0, m, &cDelay_9ZFZGq0Q_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_q1eoZw9j, 0, m, &cDelay_q1eoZw9j_sendMessage);
}

void Heavy_prog::cPack_2LD1IgzH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_9EJR0fMQ, 0, m, NULL);
}

void Heavy_prog::cCast_oI4uIjNf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ge8KwmpB_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_ge8KwmpB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cDelay_onMessage(_c, &Context(_c)->cDelay_q1eoZw9j, 1, m, &cDelay_q1eoZw9j_sendMessage);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9ZFZGq0Q, 1, m, &cDelay_9ZFZGq0Q_sendMessage);
}

void Heavy_prog::cMsg_RUB87hYx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "stop");
  sLine_onMessage(_c, &Context(_c)->sLine_9EJR0fMQ, 0, m, NULL);
}

void Heavy_prog::cCast_LUpn9HNW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4KcOaDCe_sendMessage(_c, 0, m);
}

void Heavy_prog::cCast_itsEQ3eR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RUB87hYx_sendMessage(_c, 0, m);
}

void Heavy_prog::cMsg_4KcOaDCe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cSwitchcase_hSubSJBr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cCast_SW9uKNGL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UUyEZ3S1_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cB2j5UYF_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_K99oC8aa_sendMessage);
}

void Heavy_prog::cCast_TtGPo869_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_U3XCOUBP_sendMessage);
}

void Heavy_prog::cCast_UUyEZ3S1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QWs5OS1T, 0, m, &cVar_QWs5OS1T_sendMessage);
}

void Heavy_prog::cCast_cB2j5UYF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qBmmDtsc, 0, m, &cVar_qBmmDtsc_sendMessage);
}

void Heavy_prog::cCast_K99oC8aa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Mq5Fi3Fh, 0, m, &cVar_Mq5Fi3Fh_sendMessage);
}

void Heavy_prog::cMsg_YdKWnsWd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cSwitchcase_tjlGOmkh_onMessage(_c, NULL, 0, m, NULL);
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setElementToFrom(m, 1, n, 1);
  msg_setElementToFrom(m, 2, n, 2);
  cSwitchcase_tjlGOmkh_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_prog::cBinop_GXFsseLj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jVl6QLbI, 0, m, &cVar_jVl6QLbI_sendMessage);
}

void Heavy_prog::cBinop_Xxx8qrTU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nutjQ3Ru, 0, m, &cVar_nutjQ3Ru_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.0f, 0, m, &cBinop_vRd5dChk_sendMessage);
}

void Heavy_prog::cBinop_vRd5dChk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6QPphwpk, 0, m, &cVar_6QPphwpk_sendMessage);
}

void Heavy_prog::cBinop_j3ijTEpo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_5JG3lF6I, 0, m, &cVar_5JG3lF6I_sendMessage);
}

void Heavy_prog::cReceive_DTwMSfIL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YqOnEL9n_sendMessage(_c, 0, m);
  cMsg_FEBo2Yri_sendMessage(_c, 0, m);
  cMsg_fND9TiaK_sendMessage(_c, 0, m);
  cMsg_ZXO3U6By_sendMessage(_c, 0, m);
  cMsg_J8zuecjZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_mkywTWXq, 0, m, &cVar_mkywTWXq_sendMessage);
  cMsg_x8VvW1Cx_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LpTlsNAz, 0, m, &cVar_LpTlsNAz_sendMessage);
  cMsg_CYBsaUyk_sendMessage(_c, 0, m);
  cMsg_q5pt7pvL_sendMessage(_c, 0, m);
  cSwitchcase_LSJI0p9M_onMessage(_c, NULL, 0, m, NULL);
  cMsg_zLXzGPqp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_t3poRff3, 0, m, &cVar_t3poRff3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_iYjx5fiq, 0, m, &cVar_iYjx5fiq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MwEqr9aS, 0, m, &cVar_MwEqr9aS_sendMessage);
  cMsg_1wG5V4WJ_sendMessage(_c, 0, m);
  cMsg_WOPDsI1b_sendMessage(_c, 0, m);
  cMsg_DKKkeCNS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_EllOqpYi, 0, m, &cVar_EllOqpYi_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_5qPxTDML, 0, m, &cVar_5qPxTDML_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_vywe2R7d, 0, m, &cVar_vywe2R7d_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Yh7ZaLaW, 0, m, &cVar_Yh7ZaLaW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_6glDRNGD, 0, m, &cVar_6glDRNGD_sendMessage);
  cMsg_FNIfuuk1_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VqfTk6jb, 0, m, &cVar_VqfTk6jb_sendMessage);
  cMsg_5w8tYmy4_sendMessage(_c, 0, m);
}

void Heavy_prog::cReceive_7Gnvxz6y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QWs5OS1T, 1, m, &cVar_QWs5OS1T_sendMessage);
}




/*
 * Context Process Implementation
 */

int Heavy_prog::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }

  sendBangToReceiver(0xDD21C0EB); // send to __hv_bang~ on next cycle
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8, Bf9, Bf10, Bf11, Bf12;
  hv_bufferi_t Bi0, Bi1;

  // input and output vars
  hv_bufferf_t O0, O1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_varread_f(&sVarf_4s2HcG77, VOf(Bf0));
    __hv_varread_f(&sVarf_joS7FMdj, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_phasor_f(&sPhasor_gNoeGD7y, VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f, 2.0f);
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf1), VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_INqueJBO, VOf(Bf2));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_phasor_f(&sPhasor_CPwgIEw7, VIf(Bf0), VOf(Bf0));
    __hv_neg_f(VIf(Bf0), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_min_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f);
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf3), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_line_f(&sLine_qwgTv6Iy, VOf(Bf0));
    __hv_zero_f(VOf(Bf3));
    __hv_pow_f(VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_min_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
    __hv_max_f(VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_mul_f(VIf(Bf3), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f, 0.4f);
    __hv_var_k_f(VOf(Bf0), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_phasor_k_f(&sPhasor_yzmlOvph, VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf4), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf1));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf1), VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_phasor_k_f(&sPhasor_g92OtMmv, VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf6));
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf8), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf7), VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf6), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf4), VIf(Bf1), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_line_f(&sLine_ISnsxs6B, VOf(Bf4));
    __hv_varread_f(&sVarf_Jz6YwMZ9, VOf(Bf8));
    __hv_mul_f(VIf(Bf4), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_mul_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_fma_f(VIf(Bf5), VIf(Bf6), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_LXPyvtOw, VOf(Bf6));
    __hv_varread_f(&sVarf_Eo5uVgAQ, VOf(Bf5));
    __hv_fma_f(VIf(Bf8), VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_phasor_f(&sPhasor_SsDKYspL, VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf8), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf5), VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_jsJlLOQh, VOf(Bf6));
    __hv_varread_f(&sVarf_Q1f0npz2, VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_phasor_f(&sPhasor_R2rjPAPz, VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_wd5Y9tHI, VOf(Bf5));
    __hv_varread_f(&sVarf_reah5MgV, VOf(Bf7));
    __hv_fms_f(VIf(Bf1), VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_sub_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_phasor_f(&sPhasor_OLrMGZuH, VIf(Bf7), VOf(Bf7));
    __hv_neg_f(VIf(Bf7), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_add_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_min_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf7), 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f, 4.0f);
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_fms_f(VIf(Bf5), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_9EJR0fMQ, VOf(Bf7));
    __hv_zero_f(VOf(Bf5));
    __hv_pow_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_min_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf5), -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
    __hv_max_f(VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf4), VIf(Bf6), VOf(Bf5));
    __hv_phasor_k_f(&sPhasor_wD7kWVbt, VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf1), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf7));
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf9), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf10), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf8), VIf(Bf10), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf7), VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_phasor_k_f(&sPhasor_YRindpgD, VOf(Bf9));
    __hv_var_k_f(VOf(Bf7), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_abs_f(VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf9), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf7), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf9), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf7), VOf(Bf9));
    __hv_mul_f(VIf(Bf7), VIf(Bf9), VOf(Bf10));
    __hv_mul_f(VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf8), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf11), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf10), VIf(Bf11), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf9), VIf(Bf8), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf1), VIf(Bf7), VOf(Bf8));
    __hv_var_k_f(VOf(Bf9), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_mul_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_line_f(&sLine_cVWspHuH, VOf(Bf1));
    __hv_varread_f(&sVarf_Wh6MsQGV, VOf(Bf11));
    __hv_mul_f(VIf(Bf1), VIf(Bf11), VOf(Bf11));
    __hv_sub_f(VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_mul_f(VIf(Bf7), VIf(Bf11), VOf(Bf11));
    __hv_fma_f(VIf(Bf8), VIf(Bf9), VIf(Bf11), VOf(Bf11));
    __hv_varread_f(&sVarf_CJN8HIfH, VOf(Bf9));
    __hv_varread_f(&sVarf_GlloTte0, VOf(Bf8));
    __hv_fma_f(VIf(Bf11), VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_phasor_f(&sPhasor_GLHcENgr, VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf9), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_abs_f(VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf8), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf9), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf9), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf8), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf9), VIf(Bf9), VOf(Bf8));
    __hv_mul_f(VIf(Bf9), VIf(Bf8), VOf(Bf11));
    __hv_mul_f(VIf(Bf11), VIf(Bf8), VOf(Bf8));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf10), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf11), VIf(Bf10), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf8), VIf(Bf7), VIf(Bf9), VOf(Bf9));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf9), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf9), 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f);
    __hv_mul_f(VIf(Bf1), VIf(Bf9), VOf(Bf9));
    __hv_add_f(VIf(Bf5), VIf(Bf9), VOf(Bf5));
    __hv_fma_f(VIf(Bf2), VIf(Bf0), VIf(Bf5), VOf(Bf5));
    __hv_line_f(&sLine_b06M6EJs, VOf(Bf0));
    __hv_tabhead_f(&sTabhead_jbxl0hw2, VOf(Bf1));
    __hv_var_k_f_r(VOf(Bf7), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_Po7eldEU, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_R0sGSf7M, VOf(Bf0));
    __hv_min_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf1));
    __hv_max_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_floor_f(VIf(Bf1), VOf(Bf7));
    __hv_varread_f(&sVarf_FJgiRSCt, VOf(Bf0));
    __hv_zero_f(VOf(Bf8));
    __hv_lt_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_and_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_add_f(VIf(Bf7), VIf(Bf8), VOf(Bf8));
    __hv_cast_fi(VIf(Bf8), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_4zUTVKiE, VIi(Bi1), VOf(Bf8));
    __hv_tabread_if(&sTabread_ip2JD7XQ, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf8), VIf(Bf0), VOf(Bf8));
    __hv_sub_f(VIf(Bf1), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf8), VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_ULnYA8c4, VOf(Bf7));
    __hv_fma_f(VIf(Bf0), VIf(Bf7), VIf(Bf5), VOf(Bf7));
    __hv_line_f(&sLine_ZPCAg4tK, VOf(Bf0));
    __hv_tabhead_f(&sTabhead_7TJCgywj, VOf(Bf8));
    __hv_var_k_f_r(VOf(Bf1), -1.0f, -2.0f, -3.0f, -4.0f, -5.0f, -6.0f, -7.0f, -8.0f);
    __hv_add_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_VXGWDsPI, VOf(Bf8));
    __hv_mul_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_varread_f(&sVarf_SmpXAesD, VOf(Bf0));
    __hv_min_f(VIf(Bf8), VIf(Bf0), VOf(Bf0));
    __hv_zero_f(VOf(Bf8));
    __hv_max_f(VIf(Bf0), VIf(Bf8), VOf(Bf8));
    __hv_sub_f(VIf(Bf1), VIf(Bf8), VOf(Bf8));
    __hv_floor_f(VIf(Bf8), VOf(Bf1));
    __hv_varread_f(&sVarf_nwfdR6Mg, VOf(Bf0));
    __hv_zero_f(VOf(Bf10));
    __hv_lt_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_and_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_add_f(VIf(Bf1), VIf(Bf10), VOf(Bf10));
    __hv_cast_fi(VIf(Bf10), VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 1, 1, 1, 1, 1, 1, 1, 1);
    __hv_add_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_tabread_if(&sTabread_qPPSvO4u, VIi(Bi1), VOf(Bf10));
    __hv_tabread_if(&sTabread_AnhwPVjn, VIi(Bi0), VOf(Bf0));
    __hv_sub_f(VIf(Bf10), VIf(Bf0), VOf(Bf10));
    __hv_sub_f(VIf(Bf8), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf10), VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_OLNqf6rw, VOf(Bf1));
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_sub_f(VIf(Bf7), VIf(Bf1), VOf(Bf1));
    __hv_tabwrite_f(&sTabwrite_qe8csanJ, VIf(Bf1));
    __hv_tabwrite_f(&sTabwrite_bMOTC4o6, VIf(Bf5));
    __hv_varread_i(&sVari_Y3QmRdRe, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf5));
    __hv_var_k_f(VOf(Bf7), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_varwrite_i(&sVari_Y3QmRdRe, VIi(Bi1));
    __hv_add_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_del1_f(&sDel1_ayHaDPeW, VIf(Bf6), VOf(Bf4));
    __hv_lt_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_samphold_f(&sSamphold_2zzi3J0r, VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_9RhbTFla, VOf(Bf7));
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_Lv1AzgcS, VOf(Bf4));
    __hv_rpole_f(&sRPole_uxrw0ldi, VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf7), 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f, 0.8f);
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf1), VIf(Bf7), VOf(Bf4));
    __hv_var_k_f(VOf(Bf6), 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f);
    __hv_line_f(&sLine_FEy95cyc, VOf(Bf5));
    __hv_varread_f(&sVarf_F5s5mKsE, VOf(Bf0));
    __hv_mul_f(VIf(Bf5), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf5), VOf(Bf0));
    __hv_floor_f(VIf(Bf0), VOf(Bf10));
    __hv_sub_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_abs_f(VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf10), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf0), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf0), 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f, 6.28319f);
    __hv_mul_f(VIf(Bf10), VIf(Bf0), VOf(Bf0));
    __hv_mul_f(VIf(Bf0), VIf(Bf0), VOf(Bf10));
    __hv_mul_f(VIf(Bf0), VIf(Bf10), VOf(Bf8));
    __hv_mul_f(VIf(Bf8), VIf(Bf10), VOf(Bf10));
    __hv_var_k_f(VOf(Bf11), 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f, 0.00784314f);
    __hv_var_k_f(VOf(Bf12), 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f, 0.166667f);
    __hv_mul_f(VIf(Bf8), VIf(Bf12), VOf(Bf12));
    __hv_sub_f(VIf(Bf0), VIf(Bf12), VOf(Bf12));
    __hv_fma_f(VIf(Bf10), VIf(Bf11), VIf(Bf12), VOf(Bf12));
    __hv_mul_f(VIf(Bf12), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf4), VIf(Bf6), VIf(Bf5), VOf(Bf6));
    __hv_add_f(VIf(Bf6), VIf(Bf9), VOf(Bf6));
    __hv_fma_f(VIf(Bf2), VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O1), VOf(O1));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_add_f(VIf(Bf2), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf2), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_add_f(VIf(Bf5), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf7), VIf(Bf2), VIf(Bf9), VOf(Bf9));
    __hv_fma_f(VIf(Bf1), VIf(Bf3), VIf(Bf9), VOf(Bf9));
    __hv_var_k_f(VOf(Bf3), 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f, 0.1f);
    __hv_mul_f(VIf(Bf9), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O0), VOf(O0));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_prog::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_prog::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
