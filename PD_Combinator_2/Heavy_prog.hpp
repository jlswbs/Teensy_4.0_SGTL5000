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

#ifndef _HEAVY_CONTEXT_PROG_HPP_
#define _HEAVY_CONTEXT_PROG_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalVar.h"
#include "HvSignalTabwrite.h"
#include "HvControlBinop.h"
#include "HvControlSystem.h"
#include "HvControlRandom.h"
#include "HvMath.h"
#include "HvSignalSamphold.h"
#include "HvSignalRPole.h"
#include "HvSignalDel1.h"
#include "HvControlSlice.h"
#include "HvControlCast.h"
#include "HvSignalTabread.h"
#include "HvControlUnop.h"
#include "HvSignalLine.h"
#include "HvControlDelay.h"
#include "HvTable.h"
#include "HvSignalPhasor.h"
#include "HvControlIf.h"
#include "HvControlPack.h"
#include "HvControlVar.h"

class Heavy_prog : public HeavyContext {

 public:
  Heavy_prog(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_prog();

  const char *getName() override { return "prog"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cVar_aiRCK1oD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Yh7ZaLaW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6T3PWVUJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_2pl4jBpU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_oUK1aQIu_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_D05BVZuL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_ZsaIafBp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_4ZgURvdc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_vrK9TF39_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_UQTwpzzV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_zvGpWtLp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_82PSRnaT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_g5VEvdj4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_NVL5jLGD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_6FofwjpR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_RqbmmAsF_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_3xYR0mjn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_bkrbrdYb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_WlQpd8A6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4LzXIU3B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_49uQdjEj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rWPuBdWg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1vx1lJNn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_G9sESCL5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_fND9TiaK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_R6OSAxJx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZXO3U6By_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_5JG3lF6I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_4DrVFaIt_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_CwoPwYzq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5R2J2JPC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_J8zuecjZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_NNl2jeBG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mkywTWXq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_cvXWpo3V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rispCD3H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xMU2aa3c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PTeaD87O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_eOdck9JL_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_098MrJol_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Z5i9I8xY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_x8VvW1Cx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_OEkt7vA0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_LpTlsNAz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sv4uTztQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XxM9sjEc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UmDJnpws_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AoRQ5956_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_dzZfk3eb_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_DKOI8Zbf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_nP21HRNf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_hBewCX0x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_0G6qF7OG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_KLY3LGks_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_QxKagxVX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Qkv5ThHK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ndlY3XOw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_JCoG3y5p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_NVeozXoq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_54xvQSZI_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_uBLLjFhs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QyHMQ2Xs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_fYLh7G1D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4XvlD1I0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_n57LjzfT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Ji6fkGOk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7MkhI79o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kwqVT4si_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CYBsaUyk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YxW06bU2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_q5pt7pvL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_otRIPRcb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_OnbjfxGY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nutjQ3Ru_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_jVl6QLbI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_LSJI0p9M_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_hNEulwuh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_9lPFIcMs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_RfJDcNjZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_6Bu9xezm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vV5SEkXI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_t3poRff3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zLXzGPqp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_X8VPuPuB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_h7jlsLxy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NxguxrRH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_cmnqwQLI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_N5yxTYbU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KrF8HKwF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zcq74E7o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_6QPphwpk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_GodFSekb_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_U4E9GPsR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_Wfylgilh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_g1rW638j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_7Spm2iIS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_bprVS7Xl_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_SkToAz6k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_7XWecGHm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_gcUPhuNH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_g7Nn7iLx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_M8cpJm7L_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_vVGhwjnk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_sLSTULwU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_k2ro9kEb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_DKTKYBLN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_4bYH7yiC_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_bjLwEH9L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5wztGdB3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vTcSO1GS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_h72jDZ7T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_DTIgZLXy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Bk1dABXY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_eRiL2yWF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_dApQoou2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_A3RLwPHc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sSD5V6Wy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_BtGPhqys_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DlLR2X2l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9dzDUlXT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ojJA8Bkt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_71Y1z5oG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Yvlh3erB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KxBxiXsX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_r1X9R6Iq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_e6Tn0GU6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7rNNT0un_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_w8TNEhMs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_T7cXIqMb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OIoTrfnH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JwQKCIR6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LBpp8JLi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9p3Xd09a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_iYjx5fiq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_MwEqr9aS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_dFZeiE3V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_1Nod8XHy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_tuBwxxga_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_ysupMWVd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_uxHPuSYv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_KmnIo8w1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_5uoj88TA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_rjybilXn_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_qCzaca8K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_nKlF56qA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_Srv0mtAA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_kcFUHI7p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_hg4XhQY4_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_Ny7ODDq3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_7pRq9alZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kheggnw3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AvgM8uc8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_NFUlCTez_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EDysp0eQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vIqIyuB2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qNpttpd5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_eKCdba70_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_NCrzSwAh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_748jSgcN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_p9TcWUzc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_tyAMXxmW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_yvYfVLPg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rQUfWe5j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xoBllgxi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xJCB7PT4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_taThuE4j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_HEiJNswg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vFErfk8W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pITKsaW4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3ezHxxDS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_N1n2CkNa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_4H1VbQv5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FNIfuuk1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Mb4EvbKU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_6glDRNGD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_GV4flLW8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qKnL2005_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_mzJ9XLhq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_u01OKzZj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5w8tYmy4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_S1nL0bMN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VqfTk6jb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_YGlsqLmT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AFC2ZIAj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_d9PYKZpu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_eojmD9rk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iKcTlPki_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ij0yeJtj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_s8O3cVoG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AUQau87V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JPwK6lRr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_W0w9ZnSH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YqOnEL9n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_AXEt3Jug_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_EiSzSbBK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_PLsdDGp0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_9oNnlIoT_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_ibXJkbG1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_Jov25Euz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0sn39kJR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EvAPuHzV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gPLdNlOt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_mTtx6Ka3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_szqOz9q9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jquMpcI5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FEBo2Yri_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_a8t8muQR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_juNN3NNb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_eMse7GWe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_5dxa58Cs_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_WpoKdTCG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void hTable_xmQkqrQL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_dYyND5N7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RLWnH31p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KQn4A1DW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7o6XpGXJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_yq5cEsRY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_G86vPzcj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UBlffBWT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_EhvtblXy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UghXGZpI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TepkTFd9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_l0RdqRrD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_93B45Qgw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1wG5V4WJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WOPDsI1b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DKKkeCNS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gz0rqwrY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_U3XCOUBP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6Z3bBouH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_S2FP6PG1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Dfu4PLzf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oB2zxYOt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DuVwESAm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nMbLbKCw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YwK2VTe5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_EllOqpYi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_5qPxTDML_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_Yfp80uRY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_QWs5OS1T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qBmmDtsc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Mq5Fi3Fh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_vywe2R7d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_e7uLgPjr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PwmdIoto_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_5gI4bLcd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_mw1Ervf5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_sFXfrfpu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_tjlGOmkh_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_u11miyXO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_q1eoZw9j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_9ZFZGq0Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_YBWhmpSZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_hSubSJBr_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_WG2PqURk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QzGltapG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KlvMXGs5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lGnBmfgb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RiMII6VF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_WdEuSaDR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_XvtfFIR4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Uoo8i25Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_2LD1IgzH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_oI4uIjNf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ge8KwmpB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RUB87hYx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_LUpn9HNW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_itsEQ3eR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_4KcOaDCe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SW9uKNGL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TtGPo869_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UUyEZ3S1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cB2j5UYF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_K99oC8aa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_YdKWnsWd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GXFsseLj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Xxx8qrTU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vRd5dChk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_j3ijTEpo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_DTwMSfIL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_7Gnvxz6y_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_gNoeGD7y;
  SignalLine sLine_INqueJBO;
  SignalPhasor sPhasor_CPwgIEw7;
  SignalLine sLine_qwgTv6Iy;
  SignalPhasor sPhasor_yzmlOvph;
  SignalPhasor sPhasor_g92OtMmv;
  SignalLine sLine_ISnsxs6B;
  SignalPhasor sPhasor_SsDKYspL;
  SignalPhasor sPhasor_R2rjPAPz;
  SignalPhasor sPhasor_OLrMGZuH;
  SignalLine sLine_9EJR0fMQ;
  SignalPhasor sPhasor_wD7kWVbt;
  SignalPhasor sPhasor_YRindpgD;
  SignalLine sLine_cVWspHuH;
  SignalPhasor sPhasor_GLHcENgr;
  SignalLine sLine_b06M6EJs;
  SignalTabhead sTabhead_jbxl0hw2;
  SignalTabread sTabread_4zUTVKiE;
  SignalTabread sTabread_ip2JD7XQ;
  SignalLine sLine_ULnYA8c4;
  SignalLine sLine_ZPCAg4tK;
  SignalTabhead sTabhead_7TJCgywj;
  SignalTabread sTabread_qPPSvO4u;
  SignalTabread sTabread_AnhwPVjn;
  SignalLine sLine_OLNqf6rw;
  SignalTabwrite sTabwrite_qe8csanJ;
  SignalTabwrite sTabwrite_bMOTC4o6;
  SignalDel1 sDel1_ayHaDPeW;
  SignalSamphold sSamphold_2zzi3J0r;
  SignalRPole sRPole_uxrw0ldi;
  SignalLine sLine_FEy95cyc;
  ControlVar cVar_aiRCK1oD;
  ControlVar cVar_Yh7ZaLaW;
  ControlBinop cBinop_6T3PWVUJ;
  ControlVar cVar_2pl4jBpU;
  ControlBinop cBinop_D05BVZuL;
  ControlRandom cRandom_4ZgURvdc;
  ControlSlice cSlice_vrK9TF39;
  ControlPack cPack_UQTwpzzV;
  ControlSlice cSlice_zvGpWtLp;
  ControlSlice cSlice_82PSRnaT;
  ControlSlice cSlice_g5VEvdj4;
  ControlSlice cSlice_NVL5jLGD;
  ControlSlice cSlice_6FofwjpR;
  SignalVarf sVarf_GlloTte0;
  ControlBinop cBinop_1vx1lJNn;
  ControlBinop cBinop_G9sESCL5;
  SignalVarf sVarf_Wh6MsQGV;
  SignalVarf sVarf_CJN8HIfH;
  ControlVar cVar_5JG3lF6I;
  ControlDelay cDelay_CwoPwYzq;
  ControlVar cVar_mkywTWXq;
  ControlBinop cBinop_rispCD3H;
  ControlBinop cBinop_xMU2aa3c;
  ControlBinop cBinop_PTeaD87O;
  ControlDelay cDelay_098MrJol;
  ControlVar cVar_LpTlsNAz;
  ControlBinop cBinop_XxM9sjEc;
  ControlBinop cBinop_UmDJnpws;
  ControlBinop cBinop_AoRQ5956;
  ControlBinop cBinop_DKOI8Zbf;
  ControlRandom cRandom_hBewCX0x;
  ControlSlice cSlice_0G6qF7OG;
  ControlPack cPack_KLY3LGks;
  ControlSlice cSlice_QxKagxVX;
  ControlSlice cSlice_Qkv5ThHK;
  ControlSlice cSlice_ndlY3XOw;
  ControlSlice cSlice_JCoG3y5p;
  ControlSlice cSlice_NVeozXoq;
  SignalVarf sVarf_Eo5uVgAQ;
  ControlBinop cBinop_7MkhI79o;
  ControlBinop cBinop_kwqVT4si;
  SignalVarf sVarf_Jz6YwMZ9;
  SignalVarf sVarf_LXPyvtOw;
  ControlVar cVar_otRIPRcb;
  ControlVar cVar_OnbjfxGY;
  ControlVar cVar_nutjQ3Ru;
  ControlVar cVar_jVl6QLbI;
  ControlBinop cBinop_hNEulwuh;
  ControlRandom cRandom_RfJDcNjZ;
  ControlSlice cSlice_6Bu9xezm;
  SignalVari sVari_Y3QmRdRe;
  ControlVar cVar_t3poRff3;
  ControlBinop cBinop_h7jlsLxy;
  ControlBinop cBinop_NxguxrRH;
  SignalVarf sVarf_Lv1AzgcS;
  ControlBinop cBinop_N5yxTYbU;
  ControlBinop cBinop_KrF8HKwF;
  ControlBinop cBinop_zcq74E7o;
  SignalVarf sVarf_9RhbTFla;
  ControlVar cVar_6QPphwpk;
  ControlBinop cBinop_U4E9GPsR;
  ControlRandom cRandom_g1rW638j;
  ControlSlice cSlice_7Spm2iIS;
  ControlBinop cBinop_SkToAz6k;
  ControlRandom cRandom_gcUPhuNH;
  ControlSlice cSlice_g7Nn7iLx;
  ControlBinop cBinop_vVGhwjnk;
  ControlRandom cRandom_k2ro9kEb;
  ControlSlice cSlice_DKTKYBLN;
  ControlVar cVar_h72jDZ7T;
  ControlVar cVar_DTIgZLXy;
  ControlVar cVar_Bk1dABXY;
  ControlVar cVar_eRiL2yWF;
  ControlBinop cBinop_sSD5V6Wy;
  SignalVarf sVarf_F5s5mKsE;
  ControlBinop cBinop_r1X9R6Iq;
  ControlBinop cBinop_e6Tn0GU6;
  ControlBinop cBinop_7rNNT0un;
  ControlBinop cBinop_w8TNEhMs;
  SignalVarf sVarf_4s2HcG77;
  ControlBinop cBinop_OIoTrfnH;
  ControlBinop cBinop_JwQKCIR6;
  ControlBinop cBinop_LBpp8JLi;
  ControlBinop cBinop_9p3Xd09a;
  ControlVar cVar_iYjx5fiq;
  ControlVar cVar_MwEqr9aS;
  ControlVar cVar_dFZeiE3V;
  ControlPack cPack_1Nod8XHy;
  ControlVar cVar_tuBwxxga;
  ControlVar cVar_ysupMWVd;
  ControlSlice cSlice_uxHPuSYv;
  ControlSlice cSlice_KmnIo8w1;
  ControlSlice cSlice_5uoj88TA;
  ControlSlice cSlice_qCzaca8K;
  ControlDelay cDelay_nKlF56qA;
  ControlDelay cDelay_Srv0mtAA;
  ControlIf cIf_kcFUHI7p;
  ControlSlice cSlice_Ny7ODDq3;
  ControlPack cPack_eKCdba70;
  SignalVarf sVarf_joS7FMdj;
  ControlPack cPack_N1n2CkNa;
  ControlPack cPack_4H1VbQv5;
  ControlVar cVar_6glDRNGD;
  ControlBinop cBinop_qKnL2005;
  ControlBinop cBinop_u01OKzZj;
  SignalVarf sVarf_FJgiRSCt;
  SignalVarf sVarf_Po7eldEU;
  SignalVarf sVarf_R0sGSf7M;
  ControlVar cVar_VqfTk6jb;
  ControlBinop cBinop_AFC2ZIAj;
  ControlBinop cBinop_eojmD9rk;
  SignalVarf sVarf_nwfdR6Mg;
  SignalVarf sVarf_VXGWDsPI;
  SignalVarf sVarf_SmpXAesD;
  ControlBinop cBinop_iKcTlPki;
  ControlBinop cBinop_Ij0yeJtj;
  ControlBinop cBinop_s8O3cVoG;
  ControlBinop cBinop_AUQau87V;
  ControlBinop cBinop_JPwK6lRr;
  ControlBinop cBinop_W0w9ZnSH;
  ControlDelay cDelay_EiSzSbBK;
  ControlDelay cDelay_PLsdDGp0;
  ControlBinop cBinop_ibXJkbG1;
  HvTable hTable_Jov25Euz;
  ControlBinop cBinop_EvAPuHzV;
  ControlDelay cDelay_juNN3NNb;
  ControlDelay cDelay_eMse7GWe;
  ControlBinop cBinop_WpoKdTCG;
  HvTable hTable_xmQkqrQL;
  ControlBinop cBinop_RLWnH31p;
  ControlBinop cBinop_l0RdqRrD;
  ControlBinop cBinop_93B45Qgw;
  ControlBinop cBinop_gz0rqwrY;
  ControlBinop cBinop_U3XCOUBP;
  ControlBinop cBinop_6Z3bBouH;
  ControlBinop cBinop_S2FP6PG1;
  SignalVarf sVarf_jsJlLOQh;
  ControlBinop cBinop_oB2zxYOt;
  ControlBinop cBinop_DuVwESAm;
  ControlBinop cBinop_nMbLbKCw;
  ControlBinop cBinop_YwK2VTe5;
  ControlVar cVar_EllOqpYi;
  ControlVar cVar_5qPxTDML;
  ControlPack cPack_Yfp80uRY;
  ControlVar cVar_QWs5OS1T;
  ControlVar cVar_qBmmDtsc;
  ControlVar cVar_Mq5Fi3Fh;
  ControlVar cVar_vywe2R7d;
  ControlBinop cBinop_e7uLgPjr;
  ControlBinop cBinop_PwmdIoto;
  ControlSlice cSlice_5gI4bLcd;
  ControlSlice cSlice_mw1Ervf5;
  ControlSlice cSlice_sFXfrfpu;
  ControlSlice cSlice_u11miyXO;
  ControlDelay cDelay_q1eoZw9j;
  ControlDelay cDelay_9ZFZGq0Q;
  ControlIf cIf_YBWhmpSZ;
  ControlSlice cSlice_WG2PqURk;
  ControlPack cPack_2LD1IgzH;
  SignalVarf sVarf_wd5Y9tHI;
  SignalVarf sVarf_reah5MgV;
  SignalVarf sVarf_Q1f0npz2;
  ControlBinop cBinop_GXFsseLj;
  ControlBinop cBinop_Xxx8qrTU;
  ControlBinop cBinop_vRd5dChk;
  ControlBinop cBinop_j3ijTEpo;
};

#endif // _HEAVY_CONTEXT_PROG_HPP_
