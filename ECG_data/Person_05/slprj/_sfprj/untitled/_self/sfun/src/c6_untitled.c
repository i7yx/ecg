/* Include files */

#include "untitled_sfun.h"
#include "c6_untitled.h"
#include <string.h>
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c6_emlrtMCI = { 14, /* lineNo */
  37,                                  /* colNo */
  "validatefinite",                    /* fName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+valattr\\validatefinite.m"/* pName */
};

static emlrtMCInfo c6_b_emlrtMCI = { 87,/* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c6_c_emlrtMCI = { 152,/* lineNo */
  5,                                   /* colNo */
  "filter",                            /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m"/* pName */
};

static emlrtMCInfo c6_d_emlrtMCI = { 154,/* lineNo */
  5,                                   /* colNo */
  "filter",                            /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\datafun\\filter.m"/* pName */
};

static emlrtMCInfo c6_e_emlrtMCI = { 242,/* lineNo */
  13,                                  /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtMCInfo c6_f_emlrtMCI = { 245,/* lineNo */
  13,                                  /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtMCInfo c6_g_emlrtMCI = { 409,/* lineNo */
  5,                                   /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtMCInfo c6_h_emlrtMCI = { 420,/* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtMCInfo c6_i_emlrtMCI = { 447,/* lineNo */
  5,                                   /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtMCInfo c6_j_emlrtMCI = { 398,/* lineNo */
  5,                                   /* colNo */
  "colon",                             /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtMCInfo c6_k_emlrtMCI = { 419,/* lineNo */
  15,                                  /* colNo */
  "colon",                             /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtMCInfo c6_l_emlrtMCI = { 62,/* lineNo */
  39,                                  /* colNo */
  "stack",                             /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\stack.m"/* pName */
};

static emlrtMCInfo c6_m_emlrtMCI = { 82,/* lineNo */
  13,                                  /* colNo */
  "stack",                             /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\stack.m"/* pName */
};

static emlrtMCInfo c6_n_emlrtMCI = { 122,/* lineNo */
  5,                                   /* colNo */
  "indexShapeCheck",                   /* fName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pName */
};

static emlrtMCInfo c6_o_emlrtMCI = { 48,/* lineNo */
  15,                                  /* colNo */
  "mean",                              /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m"/* pName */
};

static emlrtRSInfo c6_emlrtRSI = { 10, /* lineNo */
  "MATLAB Function5",                  /* fcnName */
  "#untitled:78"                       /* pathName */
};

static emlrtRSInfo c6_b_emlrtRSI = { 25,/* lineNo */
  "MATLAB Function5",                  /* fcnName */
  "#untitled:78"                       /* pathName */
};

static emlrtRSInfo c6_c_emlrtRSI = { 29,/* lineNo */
  "MATLAB Function5",                  /* fcnName */
  "#untitled:78"                       /* pathName */
};

static emlrtRSInfo c6_d_emlrtRSI = { 123,/* lineNo */
  "filtfilt",                          /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo c6_e_emlrtRSI = { 150,/* lineNo */
  "filtfilt",                          /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo c6_f_emlrtRSI = { 505,/* lineNo */
  "filtfilt",                          /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo c6_g_emlrtRSI = { 579,/* lineNo */
  "filtfilt",                          /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo c6_h_emlrtRSI = { 93,/* lineNo */
  "validateattributes",                /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pathName */
};

static emlrtRSInfo c6_i_emlrtRSI = { 174,/* lineNo */
  "filtfilt",                          /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo c6_j_emlrtRSI = { 179,/* lineNo */
  "filtfilt",                          /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo c6_k_emlrtRSI = { 261,/* lineNo */
  "filtfilt",                          /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo c6_l_emlrtRSI = { 13,/* lineNo */
  "sparse",                            /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m"/* pathName */
};

static emlrtRSInfo c6_m_emlrtRSI = { 1450,/* lineNo */
  "sparse",                            /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\+coder\\+internal\\@sparse\\sparse.m"/* pathName */
};

static emlrtRSInfo c6_n_emlrtRSI = { 160,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c6_o_emlrtRSI = { 316,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c6_p_emlrtRSI = { 312,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c6_q_emlrtRSI = { 291,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c6_r_emlrtRSI = { 459,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c6_s_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\warning.m"/* pathName */
};

static emlrtRSInfo c6_t_emlrtRSI = { 357,/* lineNo */
  "CXSparseAPI",                       /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\CXSparseAPI.m"/* pathName */
};

static emlrtRSInfo c6_u_emlrtRSI = { 307,/* lineNo */
  "filtfilt",                          /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo c6_v_emlrtRSI = { 309,/* lineNo */
  "filtfilt",                          /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pathName */
};

static emlrtRSInfo c6_w_emlrtRSI = { 134,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c6_x_emlrtRSI = { 166,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c6_y_emlrtRSI = { 167,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c6_ab_emlrtRSI = { 178,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c6_bb_emlrtRSI = { 182,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c6_cb_emlrtRSI = { 189,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c6_db_emlrtRSI = { 195,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c6_eb_emlrtRSI = { 566,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c6_fb_emlrtRSI = { 23,/* lineNo */
  "union",                             /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\union.m"/* pathName */
};

static emlrtRSInfo c6_gb_emlrtRSI = { 97,/* lineNo */
  "eml_setop",                         /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pathName */
};

static emlrtRSInfo c6_hb_emlrtRSI = { 579,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c6_ib_emlrtRSI = { 641,/* lineNo */
  "findpeaks",                         /* fcnName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pathName */
};

static emlrtRSInfo c6_jb_emlrtRSI = { 28,/* lineNo */
  "colon",                             /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c6_kb_emlrtRSI = { 82,/* lineNo */
  "colon",                             /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c6_lb_emlrtRSI = { 140,/* lineNo */
  "colon",                             /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c6_mb_emlrtRSI = { 42,/* lineNo */
  "introsort",                         /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"/* pathName */
};

static emlrtRSInfo c6_nb_emlrtRSI = { 44,/* lineNo */
  "introsort",                         /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"/* pathName */
};

static emlrtRSInfo c6_ob_emlrtRSI = { 47,/* lineNo */
  "introsort",                         /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"/* pathName */
};

static emlrtRSInfo c6_pb_emlrtRSI = { 55,/* lineNo */
  "introsort",                         /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"/* pathName */
};

static emlrtRSInfo c6_qb_emlrtRSI = { 58,/* lineNo */
  "introsort",                         /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"/* pathName */
};

static emlrtRSInfo c6_rb_emlrtRSI = { 41,/* lineNo */
  "introsort",                         /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"/* pathName */
};

static emlrtRSInfo c6_sb_emlrtRSI = { 18,/* lineNo */
  "insertionsort",                     /* fcnName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\insertionsort.m"/* pathName */
};

static emlrtRSInfo c6_tb_emlrtRSI = { 20,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c6_ub_emlrtRSI = { 42,/* lineNo */
  "indexShapeCheck",                   /* fcnName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\indexShapeCheck.m"/* pathName */
};

static emlrtRSInfo c6_vb_emlrtRSI = { 106,/* lineNo */
  "diff",                              /* fcnName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m"/* pathName */
};

static emlrtRTEInfo c6_emlrtRTEI = { 13,/* lineNo */
  1,                                   /* colNo */
  "sparse",                            /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\sparfun\\sparse.m"/* pName */
};

static emlrtRTEInfo c6_b_emlrtRTEI = { 77,/* lineNo */
  23,                                  /* colNo */
  "diff",                              /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m"/* pName */
};

static emlrtRTEInfo c6_c_emlrtRTEI = { 78,/* lineNo */
  21,                                  /* colNo */
  "diff",                              /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\datafun\\diff.m"/* pName */
};

static emlrtRTEInfo c6_d_emlrtRTEI = { 439,/* lineNo */
  22,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_e_emlrtRTEI = { 440,/* lineNo */
  23,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_f_emlrtRTEI = { 441,/* lineNo */
  27,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_g_emlrtRTEI = { 526,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_h_emlrtRTEI = { 527,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_i_emlrtRTEI = { 548,/* lineNo */
  22,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_j_emlrtRTEI = { 562,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_k_emlrtRTEI = { 167,/* lineNo */
  9,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_l_emlrtRTEI = { 178,/* lineNo */
  47,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_m_emlrtRTEI = { 584,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_n_emlrtRTEI = { 585,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_o_emlrtRTEI = { 593,/* lineNo */
  30,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_p_emlrtRTEI = { 148,/* lineNo */
  24,                                  /* colNo */
  "mergesort",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\mergesort.m"/* pName */
};

static emlrtRTEInfo c6_q_emlrtRTEI = { 52,/* lineNo */
  9,                                   /* colNo */
  "mergesort",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\eml\\+coder\\+internal\\mergesort.m"/* pName */
};

static emlrtRTEInfo c6_r_emlrtRTEI = { 598,/* lineNo */
  13,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_s_emlrtRTEI = { 598,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_t_emlrtRTEI = { 600,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_u_emlrtRTEI = { 1,/* lineNo */
  30,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_v_emlrtRTEI = { 172,/* lineNo */
  20,                                  /* colNo */
  "colon",                             /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo c6_w_emlrtRTEI = { 579,/* lineNo */
  26,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_x_emlrtRTEI = { 182,/* lineNo */
  5,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_y_emlrtRTEI = { 191,/* lineNo */
  30,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_ab_emlrtRTEI = { 187,/* lineNo */
  30,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_bb_emlrtRTEI = { 189,/* lineNo */
  9,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_cb_emlrtRTEI = { 195,/* lineNo */
  5,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_db_emlrtRTEI = { 679,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_eb_emlrtRTEI = { 680,/* lineNo */
  1,                                   /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtRTEInfo c6_fb_emlrtRTEI = { 223,/* lineNo */
  24,                                  /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo c6_gb_emlrtRTEI = { 224,/* lineNo */
  25,                                  /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo c6_hb_emlrtRTEI = { 225,/* lineNo */
  25,                                  /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo c6_ib_emlrtRTEI = { 415,/* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo c6_jb_emlrtRTEI = { 426,/* lineNo */
  13,                                  /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo c6_kb_emlrtRTEI = { 451,/* lineNo */
  9,                                   /* colNo */
  "eml_setop",                         /* fName */
  "F:\\matlab\\toolbox\\eml\\lib\\matlab\\ops\\private\\eml_setop.m"/* pName */
};

static emlrtRTEInfo c6_lb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "introsort",                         /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\introsort.m"/* pName */
};

static emlrtRTEInfo c6_mb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "insertionsort",                     /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\insertionsort.m"/* pName */
};

static emlrtRTEInfo c6_nb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "heapsort",                          /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\heapsort.m"/* pName */
};

static emlrtRTEInfo c6_ob_emlrtRTEI = { 40,/* lineNo */
  14,                                  /* colNo */
  "heapsort",                          /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\heapsort.m"/* pName */
};

static emlrtRTEInfo c6_pb_emlrtRTEI = { 48,/* lineNo */
  45,                                  /* colNo */
  "stack",                             /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\stack.m"/* pName */
};

static emlrtRTEInfo c6_qb_emlrtRTEI = { 261,/* lineNo */
  19,                                  /* colNo */
  "filtfilt",                          /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\filtfilt.m"/* pName */
};

static emlrtRTEInfo c6_rb_emlrtRTEI = { 618,/* lineNo */
  18,                                  /* colNo */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m"/* pName */
};

static emlrtBCInfo c6_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  562,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_b_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  562,                                 /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_c_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  528,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_d_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  527,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_e_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  475,                                 /* lineNo */
  14,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_f_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  526,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_g_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  502,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_h_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  523,                                 /* lineNo */
  14,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_i_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  511,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_j_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  497,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_k_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  489,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_l_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  195,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_m_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  195,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_n_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  552,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_o_emlrtBCI = { 1,/* iFirst */
  2500,                                /* iLast */
  553,                                 /* lineNo */
  12,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_p_emlrtBCI = { 1,/* iFirst */
  2500,                                /* iLast */
  555,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_q_emlrtBCI = { 1,/* iFirst */
  2500,                                /* iLast */
  555,                                 /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_r_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  558,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_s_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  598,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_t_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  195,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_u_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  603,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_v_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  628,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_w_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  623,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_x_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  619,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_y_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  619,                                 /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_ab_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  619,                                 /* lineNo */
  67,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_bb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  619,                                 /* lineNo */
  85,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_cb_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  619,                                 /* lineNo */
  100,                                 /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c6_db_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  619,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "findpeaks",                         /* fName */
  "F:\\matlab\\toolbox\\signal\\signal\\findpeaks.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c6_emlrtDCI = { 48, /* lineNo */
  63,                                  /* colNo */
  "stack",                             /* fName */
  "F:\\matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\stack.m",/* pName */
  4                                    /* checkKind */
};

/* Function Declarations */
static void initialize_c6_untitled(SFc6_untitledInstanceStruct *chartInstance);
static void initialize_params_c6_untitled(SFc6_untitledInstanceStruct
  *chartInstance);
static void mdl_start_c6_untitled(SFc6_untitledInstanceStruct *chartInstance);
static void mdl_terminate_c6_untitled(SFc6_untitledInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c6_untitled(SFc6_untitledInstanceStruct *
  chartInstance);
static void mdl_cleanup_runtime_resources_c6_untitled
  (SFc6_untitledInstanceStruct *chartInstance);
static void enable_c6_untitled(SFc6_untitledInstanceStruct *chartInstance);
static void disable_c6_untitled(SFc6_untitledInstanceStruct *chartInstance);
static void sf_gateway_c6_untitled(SFc6_untitledInstanceStruct *chartInstance);
static void ext_mode_exec_c6_untitled(SFc6_untitledInstanceStruct *chartInstance);
static void c6_update_jit_animation_c6_untitled(SFc6_untitledInstanceStruct
  *chartInstance);
static void c6_do_animation_call_c6_untitled(SFc6_untitledInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c6_untitled(SFc6_untitledInstanceStruct
  *chartInstance);
static void set_sim_state_c6_untitled(SFc6_untitledInstanceStruct *chartInstance,
  const mxArray *c6_st);
static void c6_introsort(SFc6_untitledInstanceStruct *chartInstance, int32_T
  c6_b_x[10], c6_anonymous_function *c6_cmp, int32_T c6_c_x[10]);
static void c6_insertionsort(SFc6_untitledInstanceStruct *chartInstance, int32_T
  c6_b_x[10], c6_anonymous_function *c6_cmp, int32_T c6_c_x[10]);
static void c6_check_forloop_overflow_error(SFc6_untitledInstanceStruct
  *chartInstance, const emlrtStack *c6_sp);
static void c6_warning(SFc6_untitledInstanceStruct *chartInstance, const
  emlrtStack *c6_sp);
static void c6_filter(SFc6_untitledInstanceStruct *chartInstance, const
                      emlrtStack *c6_sp, real_T c6_b[5], real_T c6_a[5], real_T
                      c6_b_x[2524], real_T c6_zi[4], real_T c6_y[2524]);
static real_T c6_sumColumnB(SFc6_untitledInstanceStruct *chartInstance, real_T
  c6_b_x[2500], int32_T c6_vlen, int32_T c6_vstart);
static real_T c6_b_sumColumnB(SFc6_untitledInstanceStruct *chartInstance, real_T
  c6_b_x[2500]);
static void c6_findpeaks(SFc6_untitledInstanceStruct *chartInstance, const
  emlrtStack *c6_sp, real_T c6_Yin[2500], real_T c6_varargin_2, real_T
  c6_Ypk_data[], int32_T c6_Ypk_size[1], real_T c6_Xpk_data[], int32_T
  c6_Xpk_size[1]);
static void c6_do_vectors(SFc6_untitledInstanceStruct *chartInstance, const
  emlrtStack *c6_sp, int32_T c6_a_data[], int32_T c6_a_size[1], int32_T
  c6_b_data[], int32_T c6_b_size[1], int32_T c6_c_data[], int32_T c6_c_size[1],
  int32_T c6_ia_data[], int32_T c6_ia_size[1], int32_T c6_ib_data[], int32_T
  c6_ib_size[1]);
static boolean_T c6_issorted(SFc6_untitledInstanceStruct *chartInstance, int32_T
  c6_x_data[], int32_T c6_x_size[1]);
static void c6_b_introsort(SFc6_untitledInstanceStruct *chartInstance, const
  emlrtStack *c6_sp, int32_T c6_x_data[], int32_T c6_x_size[1], int32_T c6_xend,
  int32_T c6_b_x_data[], int32_T c6_b_x_size[1]);
static void c6_b_insertionsort(SFc6_untitledInstanceStruct *chartInstance,
  int32_T c6_x_data[], int32_T c6_x_size[1], int32_T c6_xend, int32_T
  c6_b_x_data[], int32_T c6_b_x_size[1]);
static void c6_c_insertionsort(SFc6_untitledInstanceStruct *chartInstance, const
  emlrtStack *c6_sp, int32_T c6_x_data[], int32_T c6_x_size[1], int32_T
  c6_xstart, int32_T c6_xend, int32_T c6_b_x_data[], int32_T c6_b_x_size[1]);
static void c6_heapsort(SFc6_untitledInstanceStruct *chartInstance, int32_T
  c6_x_data[], int32_T c6_x_size[1], int32_T c6_xstart, int32_T c6_xend, int32_T
  c6_b_x_data[], int32_T c6_b_x_size[1]);
static void c6_heapify(SFc6_untitledInstanceStruct *chartInstance, int32_T
  c6_x_data[], int32_T c6_x_size[1], int32_T c6_idx, int32_T c6_xstart, int32_T
  c6_xend, int32_T c6_b_x_data[], int32_T c6_b_x_size[1]);
static void c6_indexShapeCheck(SFc6_untitledInstanceStruct *chartInstance);
static void c6_b_indexShapeCheck(SFc6_untitledInstanceStruct *chartInstance,
  const emlrtStack *c6_sp, int32_T c6_matrixSize, int32_T c6_indexSize[2]);
static real_T c6_c_sumColumnB(SFc6_untitledInstanceStruct *chartInstance, real_T
  c6_x_data[], int32_T c6_vlen);
static real_T c6_emlrt_marshallIn(SFc6_untitledInstanceStruct *chartInstance,
  const mxArray *c6_nullptr, const char_T *c6_identifier);
static real_T c6_b_emlrt_marshallIn(SFc6_untitledInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_emlrt_marshallIn(SFc6_untitledInstanceStruct *chartInstance,
  const mxArray *c6_nullptr, const char_T *c6_identifier, real_T c6_y[2500]);
static void c6_d_emlrt_marshallIn(SFc6_untitledInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[2500]);
static real_T c6_e_emlrt_marshallIn(SFc6_untitledInstanceStruct *chartInstance,
  const mxArray *c6_nullptr, const char_T *c6_identifier, boolean_T *c6_svPtr);
static real_T c6_f_emlrt_marshallIn(SFc6_untitledInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, boolean_T
  *c6_svPtr);
static void c6_slStringInitializeDynamicBuffers(SFc6_untitledInstanceStruct
  *chartInstance);
static const mxArray *c6_feval(SFc6_untitledInstanceStruct *chartInstance, const
  emlrtStack *c6_sp, const mxArray *c6_input0, const mxArray *c6_input1);
static void c6_b_feval(SFc6_untitledInstanceStruct *chartInstance, const
  emlrtStack *c6_sp, const mxArray *c6_input0, const mxArray *c6_input1);
static void c6_c_introsort(SFc6_untitledInstanceStruct *chartInstance, int32_T
  c6_b_x[10], c6_anonymous_function *c6_cmp);
static void c6_d_insertionsort(SFc6_untitledInstanceStruct *chartInstance,
  int32_T c6_b_x[10], c6_anonymous_function *c6_cmp);
static void c6_d_introsort(SFc6_untitledInstanceStruct *chartInstance, const
  emlrtStack *c6_sp, int32_T c6_x_data[], int32_T c6_xend);
static void c6_e_insertionsort(SFc6_untitledInstanceStruct *chartInstance,
  int32_T c6_x_data[], int32_T c6_xend);
static void c6_f_insertionsort(SFc6_untitledInstanceStruct *chartInstance, const
  emlrtStack *c6_sp, int32_T c6_x_data[], int32_T c6_xstart, int32_T c6_xend);
static void c6_b_heapsort(SFc6_untitledInstanceStruct *chartInstance, int32_T
  c6_x_data[], int32_T c6_xstart, int32_T c6_xend);
static void c6_b_heapify(SFc6_untitledInstanceStruct *chartInstance, int32_T
  c6_x_data[], int32_T c6_idx, int32_T c6_xstart, int32_T c6_xend);
static void c6_array_real_T_SetSize(SFc6_untitledInstanceStruct *chartInstance,
  const emlrtStack *c6_sp, c6_coder_array_real_T *c6_coderArray, const
  emlrtRTEInfo *c6_srcLocation, int32_T c6_size0);
static void c6_array_int32_T_SetSize(SFc6_untitledInstanceStruct *chartInstance,
  const emlrtStack *c6_sp, c6_coder_array_int32_T *c6_coderArray, const
  emlrtRTEInfo *c6_srcLocation, int32_T c6_size0);
static void c6_array_sparse_Constructor(SFc6_untitledInstanceStruct
  *chartInstance, c6_sparse *c6_pStruct);
static void c6_array_real_T_Constructor(SFc6_untitledInstanceStruct
  *chartInstance, c6_coder_array_real_T *c6_coderArray);
static void c6_array_int32_T_Constructor(SFc6_untitledInstanceStruct
  *chartInstance, c6_coder_array_int32_T *c6_coderArray);
static void c6_array_real_T_Destructor(SFc6_untitledInstanceStruct
  *chartInstance, c6_coder_array_real_T *c6_coderArray);
static void c6_array_sparse_Destructor(SFc6_untitledInstanceStruct
  *chartInstance, c6_sparse *c6_pStruct);
static void c6_array_int32_T_Destructor(SFc6_untitledInstanceStruct
  *chartInstance, c6_coder_array_int32_T *c6_coderArray);
static int32_T c6_div_nzp_s32(SFc6_untitledInstanceStruct *chartInstance,
  int32_T c6_numerator, int32_T c6_denominator, int32_T c6_EMLOvCount_src_loc,
  uint32_T c6_ssid_src_loc, int32_T c6_offset_src_loc, int32_T c6_length_src_loc);
static int32_T c6__s32_add__(SFc6_untitledInstanceStruct *chartInstance, int32_T
  c6_b, int32_T c6_c, int32_T c6_EMLOvCount_src_loc, uint32_T c6_ssid_src_loc,
  int32_T c6_offset_src_loc, int32_T c6_length_src_loc);
static int32_T c6__s32_minus__(SFc6_untitledInstanceStruct *chartInstance,
  int32_T c6_b, int32_T c6_c, int32_T c6_EMLOvCount_src_loc, uint32_T
  c6_ssid_src_loc, int32_T c6_offset_src_loc, int32_T c6_length_src_loc);
static void init_dsm_address_info(SFc6_untitledInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc6_untitledInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c6_untitled(SFc6_untitledInstanceStruct *chartInstance)
{
  emlrtStack c6_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c6_st.tls = chartInstance->c6_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c6_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "signal_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c6_bpm_val_not_empty = false;
  chartInstance->c6_doneDoubleBufferReInit = false;
  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c6_untitled(SFc6_untitledInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c6_untitled(SFc6_untitledInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c6_untitled(SFc6_untitledInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c6_untitled(SFc6_untitledInstanceStruct *
  chartInstance)
{
  static const uint32_T c6_decisionTxtEndIdx = 0U;
  static const uint32_T c6_decisionTxtStartIdx = 0U;
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c6_JITStateAnimation[0],
                        &chartInstance->c6_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c6_covrtInstance, 1U, 0U, 1U,
    16U);
  covrtChartInitFcn(chartInstance->c6_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c6_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c6_decisionTxtStartIdx, &c6_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c6_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c6_covrtInstance, "", 4U, 0U, 1U, 0U, 2U, 0U,
                  0U, 0U, 0U, 0U, 0U, 0U);
  covrtEmlFcnInitFcn(chartInstance->c6_covrtInstance, 4U, 0U, 0U, "c6_untitled",
                     0, -1, 971);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 0U, 0U, 189, 208, -1,
                    226, false);
  covrtEmlIfInitFcn(chartInstance->c6_covrtInstance, 4U, 0U, 1U, 800, 820, -1,
                    948, false);
  covrtEmlRelationalInitFcn(chartInstance->c6_covrtInstance, 4U, 0U, 0U, 803,
    820, -1, 5U);
}

static void mdl_cleanup_runtime_resources_c6_untitled
  (SFc6_untitledInstanceStruct *chartInstance)
{
  covrtDeleteStateflowInstanceData(chartInstance->c6_covrtInstance);
}

static void enable_c6_untitled(SFc6_untitledInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c6_untitled(SFc6_untitledInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c6_untitled(SFc6_untitledInstanceStruct *chartInstance)
{
  static real_T c6_dv[10] = { -2.8000503652844579, 5.4393397877934095,
    -3.4763426471814824, 0.83718165125602328, 1.0, 1.0, 1.0, -1.0, -1.0, -1.0 };

  static real_T c6_b_A[5] = { 1.0, -3.8000503652844579, 5.4393397877934095,
    -3.4763426471814824, 0.83718165125602328 };

  static real_T c6_b_B[5] = { 0.003621681514928607, 0.0, -0.007243363029857214,
    0.0, 0.003621681514928607 };

  static real_T c6_dv1[4] = { 0.013762572163748422, -0.026942919392724297,
    0.012590205904855154, 0.00058967620393725979 };

  static real_T c6_rhs[4] = { 0.013762572163748422, -0.026942919392724297,
    0.012590205904855154, 0.00058967620393725979 };

  static int32_T c6_a[10] = { 1, 1, 1, 1, 2, 3, 4, 2, 3, 4 };

  static int32_T c6_e_b[10] = { 1, 2, 3, 4, 2, 3, 4, 1, 2, 3 };

  static char_T c6_cv1[46] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'V', 'a', 'l', 'i', 'd', 'a', 't', 'e', 'a', 't', 't',
    'r', 'i', 'b', 'u', 't', 'e', 's', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd',
    'F', 'i', 'n', 'i', 't', 'e' };

  static char_T c6_cv3[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  static char_T c6_cv[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'f', 'i', 'l',
    't', 'f', 'i', 'l', 't', ':', 'e', 'x', 'p', 'e', 'c', 't', 'e', 'd', 'F',
    'i', 'n', 'i', 't', 'e' };

  static char_T c6_cv2[12] = { 'i', 'n', 'p', 'u', 't', ' ', 's', 'i', 'g', 'n',
    'a', 'l' };

  cs_di *c6_b_cxA;
  cs_di *c6_cxA;
  cs_din *c6_N;
  cs_din *c6_b_N;
  cs_dis *c6_S;
  cs_dis *c6_b_S;
  c6_anonymous_function c6_this;
  c6_sparse c6_d_y;
  c6_sq3iTKtlghZHnDrR1uJNnIC c6_workspace;
  emlrtStack c6_b_st;
  emlrtStack c6_c_st;
  emlrtStack c6_d_st;
  emlrtStack c6_e_st;
  emlrtStack c6_f_st;
  emlrtStack c6_g_st;
  emlrtStack c6_h_st;
  emlrtStack c6_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *c6_b_y = NULL;
  const mxArray *c6_c_y = NULL;
  const mxArray *c6_k_y = NULL;
  const mxArray *c6_l_y = NULL;
  const mxArray *c6_y = NULL;
  real_T c6_b_pks_data[2500];
  real_T c6_locs_data[2500];
  real_T c6_sq_ecg[2500];
  real_T c6_y1_data[2499];
  real_T c6_A[5];
  real_T c6_B[5];
  real_T c6_c_A[5];
  real_T c6_c_B[5];
  real_T c6_e_y[4];
  real_T c6_outBuff[4];
  real_T c6_ySize[2];
  real_T c6_work_data[1];
  real_T c6_accumulatedData;
  real_T c6_accumulatedWeights;
  real_T c6_b_a;
  real_T c6_b_accumulatedData;
  real_T c6_b_bpm;
  real_T c6_b_k;
  real_T c6_b_tmp1;
  real_T c6_b_tmp2;
  real_T c6_b_x;
  real_T c6_c_x;
  real_T c6_current_bpm;
  real_T c6_d;
  real_T c6_d1;
  real_T c6_d_x;
  real_T c6_f_b;
  real_T c6_f_y;
  real_T c6_g_b;
  real_T c6_g_y;
  real_T c6_h_y;
  real_T c6_i_y;
  real_T c6_j_y;
  real_T c6_m_y;
  real_T c6_rr;
  real_T c6_threshold;
  real_T c6_tmp1;
  real_T c6_tmp2;
  real_T c6_tol;
  real_T c6_val;
  real_T c6_work;
  int32_T c6_cidxInt[10];
  int32_T c6_ridxInt[10];
  int32_T c6_sortedIndices[10];
  int32_T c6_locs_size[1];
  int32_T c6_pks_size[1];
  int32_T c6_y1_size[1];
  int32_T c6_b_c;
  int32_T c6_b_i;
  int32_T c6_b_ixLead;
  int32_T c6_b_iyLead;
  int32_T c6_b_m;
  int32_T c6_b_n;
  int32_T c6_b_vlen;
  int32_T c6_b_vstart;
  int32_T c6_c;
  int32_T c6_c_c;
  int32_T c6_c_k;
  int32_T c6_c_vlen;
  int32_T c6_c_vstart;
  int32_T c6_count;
  int32_T c6_counts;
  int32_T c6_cptr;
  int32_T c6_currRowIdx;
  int32_T c6_d_c;
  int32_T c6_d_k;
  int32_T c6_d_vlen;
  int32_T c6_d_vstart;
  int32_T c6_dimSize;
  int32_T c6_e_k;
  int32_T c6_e_vlen;
  int32_T c6_f_k;
  int32_T c6_f_vlen;
  int32_T c6_g_k;
  int32_T c6_g_vlen;
  int32_T c6_h_b;
  int32_T c6_h_k;
  int32_T c6_h_vlen;
  int32_T c6_i;
  int32_T c6_i1;
  int32_T c6_i10;
  int32_T c6_i11;
  int32_T c6_i12;
  int32_T c6_i13;
  int32_T c6_i14;
  int32_T c6_i15;
  int32_T c6_i16;
  int32_T c6_i17;
  int32_T c6_i18;
  int32_T c6_i19;
  int32_T c6_i2;
  int32_T c6_i20;
  int32_T c6_i21;
  int32_T c6_i22;
  int32_T c6_i23;
  int32_T c6_i24;
  int32_T c6_i25;
  int32_T c6_i26;
  int32_T c6_i27;
  int32_T c6_i3;
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_i7;
  int32_T c6_i8;
  int32_T c6_i9;
  int32_T c6_iLeft;
  int32_T c6_iRight;
  int32_T c6_i_b;
  int32_T c6_i_k;
  int32_T c6_i_vlen;
  int32_T c6_idx;
  int32_T c6_ipnf;
  int32_T c6_ixLead;
  int32_T c6_iyLead;
  int32_T c6_j_k;
  int32_T c6_k;
  int32_T c6_k_k;
  int32_T c6_l_k;
  int32_T c6_m;
  int32_T c6_m_k;
  int32_T c6_n;
  int32_T c6_n_k;
  int32_T c6_newDimSize;
  int32_T c6_outputIdx;
  int32_T c6_ridx;
  int32_T c6_vlen;
  int32_T c6_vstart;
  boolean_T c6_b;
  boolean_T c6_b1;
  boolean_T c6_b2;
  boolean_T c6_b3;
  boolean_T c6_b_b;
  boolean_T c6_c_b;
  boolean_T c6_d_b;
  boolean_T c6_exitg1;
  boolean_T c6_overflow;
  boolean_T c6_p;
  c6_st.tls = chartInstance->c6_fEmlrtCtx;
  c6_b_st.prev = &c6_st;
  c6_b_st.tls = c6_st.tls;
  c6_c_st.prev = &c6_b_st;
  c6_c_st.tls = c6_b_st.tls;
  c6_d_st.prev = &c6_c_st;
  c6_d_st.tls = c6_c_st.tls;
  c6_e_st.prev = &c6_d_st;
  c6_e_st.tls = c6_d_st.tls;
  c6_f_st.prev = &c6_e_st;
  c6_f_st.tls = c6_e_st.tls;
  c6_g_st.prev = &c6_f_st;
  c6_g_st.tls = c6_f_st.tls;
  c6_h_st.prev = &c6_g_st;
  c6_h_st.tls = c6_g_st.tls;
  for (c6_i = 0; c6_i < 2500; c6_i++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 0U,
                      (*chartInstance->c6_ecg_in)[c6_i]);
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_JITTransitionAnimation[0] = 0U;
  chartInstance->c6_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c6_covrtInstance, 4U, 0, 0);
  if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 0, 0,
                     !chartInstance->c6_bpm_val_not_empty)) {
    chartInstance->c6_bpm_val = 0.0;
    chartInstance->c6_bpm_val_not_empty = true;
  }

  c6_b_st.site = &c6_emlrtRSI;
  for (c6_i1 = 0; c6_i1 < 2500; c6_i1++) {
    chartInstance->c6_Y[c6_i1] = (*chartInstance->c6_ecg_in)[c6_i1];
  }

  c6_c_st.site = &c6_d_emlrtRSI;
  c6_d_st.site = &c6_f_emlrtRSI;
  c6_e_st.site = &c6_g_emlrtRSI;
  c6_f_st.site = &c6_h_emlrtRSI;
  c6_p = true;
  c6_k = 0;
  c6_exitg1 = false;
  while ((!c6_exitg1) && (c6_k < 2500)) {
    c6_b_k = (real_T)c6_k + 1.0;
    c6_b_x = chartInstance->c6_Y[(int32_T)c6_b_k - 1];
    c6_c_x = c6_b_x;
    c6_b_b = muDoubleScalarIsInf(c6_c_x);
    c6_b1 = !c6_b_b;
    c6_d_x = c6_b_x;
    c6_c_b = muDoubleScalarIsNaN(c6_d_x);
    c6_b2 = !c6_c_b;
    c6_d_b = (c6_b1 && c6_b2);
    if (c6_d_b) {
      c6_k++;
    } else {
      c6_p = false;
      c6_exitg1 = true;
    }
  }

  if (c6_p) {
    c6_b = true;
  } else {
    c6_b = false;
  }

  if (!c6_b) {
    c6_y = NULL;
    sf_mex_assign(&c6_y, sf_mex_create("y", c6_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c6_b_y = NULL;
    sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_cv1, 10, 0U, 1, 0U, 2, 1, 46),
                  false);
    c6_c_y = NULL;
    sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_cv2, 10, 0U, 1, 0U, 2, 1, 12),
                  false);
    sf_mex_call(&c6_f_st, &c6_emlrtMCI, "error", 0U, 2U, 14, c6_y, 14,
                sf_mex_call(&c6_f_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c6_f_st, NULL, "message", 1U, 2U, 14, c6_b_y, 14, c6_c_y)));
  }

  c6_c_st.site = &c6_e_emlrtRSI;
  c6_d_st.site = &c6_i_emlrtRSI;
  c6_e_st.site = &c6_k_emlrtRSI;
  c6_f_st.site = &c6_l_emlrtRSI;
  c6_array_sparse_Constructor(chartInstance, &c6_d_y);
  for (c6_c_k = 0; c6_c_k < 10; c6_c_k++) {
    c6_d_k = c6_c_k;
    c6_sortedIndices[c6_d_k] = c6_d_k + 1;
  }

  for (c6_i2 = 0; c6_i2 < 10; c6_i2++) {
    c6_workspace.a[c6_i2] = c6_a[c6_i2];
  }

  for (c6_i3 = 0; c6_i3 < 10; c6_i3++) {
    c6_workspace.b[c6_i3] = c6_e_b[c6_i3];
  }

  c6_this.workspace = c6_workspace;
  c6_c_introsort(chartInstance, c6_sortedIndices, &c6_this);
  for (c6_e_k = 0; c6_e_k < 10; c6_e_k++) {
    c6_g_k = c6_e_k;
    c6_cidxInt[c6_g_k] = c6_a[c6_sortedIndices[c6_g_k] - 1];
  }

  for (c6_f_k = 0; c6_f_k < 10; c6_f_k++) {
    c6_h_k = c6_f_k;
    c6_ridxInt[c6_h_k] = c6_e_b[c6_sortedIndices[c6_h_k] - 1];
  }

  c6_array_real_T_SetSize(chartInstance, &c6_f_st, &c6_d_y.d, &c6_emlrtRTEI, 10);
  for (c6_i4 = 0; c6_i4 < 10; c6_i4++) {
    c6_d_y.d.vector.data[c6_i4] = 0.0;
  }

  c6_array_int32_T_SetSize(chartInstance, &c6_f_st, &c6_d_y.colidx,
    &c6_emlrtRTEI, 5);
  for (c6_i5 = 0; c6_i5 < 5; c6_i5++) {
    c6_d_y.colidx.vector.data[c6_i5] = 0;
  }

  c6_d_y.colidx.vector.data[0] = 1;
  c6_array_int32_T_SetSize(chartInstance, &c6_f_st, &c6_d_y.rowidx,
    &c6_emlrtRTEI, 10);
  for (c6_i6 = 0; c6_i6 < 10; c6_i6++) {
    c6_d_y.rowidx.vector.data[c6_i6] = 0;
  }

  c6_cptr = 0;
  for (c6_c = 0; c6_c < 4; c6_c++) {
    c6_b_c = c6_c + 1;
    while ((c6_cptr + 1 <= 10) && (c6_cidxInt[c6_cptr] == c6_b_c)) {
      c6_d_y.rowidx.vector.data[c6_cptr] = c6_ridxInt[c6_cptr];
      c6_cptr++;
    }

    c6_d_y.colidx.vector.data[c6_b_c] = c6_cptr + 1;
  }

  for (c6_i_k = 0; c6_i_k < 10; c6_i_k++) {
    c6_d_k = c6_i_k;
    c6_d_y.d.vector.data[c6_d_k] = c6_dv[c6_sortedIndices[c6_d_k] - 1];
  }

  c6_idx = 0;
  c6_i7 = c6_d_y.colidx.size[0] - 2;
  for (c6_c_c = 0; c6_c_c <= c6_i7; c6_c_c++) {
    c6_d_c = c6_c_c;
    c6_ridx = c6_d_y.colidx.vector.data[c6_d_c] - 1;
    c6_d_y.colidx.vector.data[c6_d_c] = c6_idx + 1;
    while (c6_ridx + 1 < c6_d_y.colidx.vector.data[c6_d_c + 1]) {
      c6_val = 0.0;
      c6_currRowIdx = c6_d_y.rowidx.vector.data[c6_ridx];
      while ((c6_ridx + 1 < c6_d_y.colidx.vector.data[c6_d_c + 1]) &&
             (c6_d_y.rowidx.vector.data[c6_ridx] == c6_currRowIdx)) {
        c6_val += c6_d_y.d.vector.data[c6_ridx];
        c6_ridx++;
      }

      if (c6_val != 0.0) {
        c6_d_y.d.vector.data[c6_idx] = c6_val;
        c6_d_y.rowidx.vector.data[c6_idx] = c6_currRowIdx;
        c6_idx++;
      }
    }
  }

  c6_d_y.colidx.vector.data[c6_d_y.colidx.size[0] - 1] = c6_idx + 1;
  c6_e_st.site = &c6_k_emlrtRSI;
  c6_f_st.site = &c6_m_emlrtRSI;
  c6_g_st.site = &c6_n_emlrtRSI;
  c6_h_st.site = &c6_q_emlrtRSI;
  c6_n = c6_d_y.colidx.vector.data[c6_d_y.colidx.size[0] - 1];
  c6_cxA = makeCXSparseMatrix(c6_n - 1, 4, 4, &c6_d_y.colidx.vector.data[0],
    &c6_d_y.rowidx.vector.data[0], &c6_d_y.d.vector.data[0]);
  c6_S = cs_di_sqr(2, c6_cxA, 0);
  c6_N = cs_di_lu(c6_cxA, c6_S, 1);
  cs_di_spfree(c6_cxA);
  if (c6_N == NULL) {
    c6_h_st.site = &c6_p_emlrtRSI;
    c6_warning(chartInstance, &c6_h_st);
    cs_di_sfree(c6_S);
    cs_di_nfree(c6_N);
    c6_b_n = c6_d_y.colidx.vector.data[c6_d_y.colidx.size[0] - 1];
    c6_b_cxA = makeCXSparseMatrix(c6_b_n - 1, 4, 4, &c6_d_y.colidx.vector.data[0],
      &c6_d_y.rowidx.vector.data[0], &c6_d_y.d.vector.data[0]);
    c6_b_S = cs_di_sqr(2, c6_b_cxA, 1);
    c6_b_N = cs_di_qr(c6_b_cxA, c6_b_S);
    cs_di_spfree(c6_b_cxA);
    qr_rank_di(c6_b_N, &c6_tol);
    for (c6_i10 = 0; c6_i10 < 4; c6_i10++) {
      c6_outBuff[c6_i10] = c6_dv1[c6_i10];
    }

    solve_from_qr_di(c6_b_N, c6_b_S, (double *)&c6_outBuff[0], 4, 4);
    cs_di_sfree(c6_b_S);
    cs_di_nfree(c6_b_N);
  } else {
    for (c6_i8 = 0; c6_i8 < 4; c6_i8++) {
      c6_outBuff[c6_i8] = c6_rhs[c6_i8];
    }

    solve_from_lu_di(c6_N, c6_S, (double *)&c6_outBuff[0], 4);
    cs_di_sfree(c6_S);
    cs_di_nfree(c6_N);
  }

  c6_array_sparse_Destructor(chartInstance, &c6_d_y);
  c6_d_st.site = &c6_j_emlrtRSI;
  c6_d = 2.0 * chartInstance->c6_Y[0];
  c6_d1 = 2.0 * chartInstance->c6_Y[2499];
  for (c6_i9 = 0; c6_i9 < 12; c6_i9++) {
    chartInstance->c6_ytemp[c6_i9] = c6_d - chartInstance->c6_Y[12 - c6_i9];
  }

  for (c6_i11 = 0; c6_i11 < 2500; c6_i11++) {
    chartInstance->c6_ytemp[c6_i11 + 12] = chartInstance->c6_Y[c6_i11];
  }

  for (c6_i12 = 0; c6_i12 < 12; c6_i12++) {
    chartInstance->c6_ytemp[c6_i12 + 2512] = c6_d1 - chartInstance->c6_Y[2498 -
      c6_i12];
  }

  c6_f_b = chartInstance->c6_ytemp[0];
  for (c6_i13 = 0; c6_i13 < 4; c6_i13++) {
    c6_e_y[c6_i13] = c6_outBuff[c6_i13] * c6_f_b;
  }

  for (c6_i14 = 0; c6_i14 < 2524; c6_i14++) {
    chartInstance->c6_b_ytemp[c6_i14] = chartInstance->c6_ytemp[c6_i14];
  }

  c6_e_st.site = &c6_u_emlrtRSI;
  for (c6_i15 = 0; c6_i15 < 5; c6_i15++) {
    c6_B[c6_i15] = c6_b_B[c6_i15];
  }

  for (c6_i16 = 0; c6_i16 < 5; c6_i16++) {
    c6_A[c6_i16] = c6_b_A[c6_i16];
  }

  c6_filter(chartInstance, &c6_e_st, c6_B, c6_A, chartInstance->c6_b_ytemp,
            c6_e_y, chartInstance->c6_ytemp);
  for (c6_i17 = 0; c6_i17 < 2524; c6_i17++) {
    chartInstance->c6_c_ytemp[c6_i17] = chartInstance->c6_ytemp[2523 - c6_i17];
  }

  for (c6_i18 = 0; c6_i18 < 2524; c6_i18++) {
    chartInstance->c6_ytemp[c6_i18] = chartInstance->c6_c_ytemp[c6_i18];
  }

  c6_g_b = chartInstance->c6_ytemp[0];
  for (c6_i19 = 0; c6_i19 < 4; c6_i19++) {
    c6_outBuff[c6_i19] *= c6_g_b;
  }

  for (c6_i20 = 0; c6_i20 < 2524; c6_i20++) {
    chartInstance->c6_d_ytemp[c6_i20] = chartInstance->c6_ytemp[c6_i20];
  }

  c6_e_st.site = &c6_v_emlrtRSI;
  for (c6_i21 = 0; c6_i21 < 5; c6_i21++) {
    c6_c_B[c6_i21] = c6_b_B[c6_i21];
  }

  for (c6_i22 = 0; c6_i22 < 5; c6_i22++) {
    c6_c_A[c6_i22] = c6_b_A[c6_i22];
  }

  c6_filter(chartInstance, &c6_e_st, c6_c_B, c6_c_A, chartInstance->c6_d_ytemp,
            c6_outBuff, chartInstance->c6_ytemp);
  for (c6_i23 = 0; c6_i23 < 2500; c6_i23++) {
    chartInstance->c6_Y[c6_i23] = chartInstance->c6_ytemp[2511 - c6_i23];
  }

  chartInstance->c6_x[0] = 0.0;
  for (c6_i24 = 0; c6_i24 < 2500; c6_i24++) {
    chartInstance->c6_x[c6_i24 + 1] = chartInstance->c6_Y[c6_i24];
  }

  c6_ixLead = 1;
  c6_iyLead = 0;
  c6_work = chartInstance->c6_x[0];
  for (c6_m = 0; c6_m < 2500; c6_m++) {
    c6_tmp1 = chartInstance->c6_x[c6_ixLead];
    c6_tmp2 = c6_work;
    c6_work = c6_tmp1;
    c6_tmp1 -= c6_tmp2;
    c6_ixLead++;
    chartInstance->c6_Y[c6_iyLead] = c6_tmp1;
    c6_iyLead++;
  }

  for (c6_j_k = 0; c6_j_k < 2500; c6_j_k++) {
    c6_l_k = c6__s32_add__(chartInstance, c6_j_k, 1, 0, 1U, 444, 11);
    c6_b_a = chartInstance->c6_Y[c6__s32_minus__(chartInstance, c6_l_k, 1, 0, 1U,
      444, 11)];
    c6_f_y = c6_b_a * c6_b_a;
    c6_sq_ecg[c6__s32_minus__(chartInstance, c6_l_k, 1, 0, 1U, 444, 11)] =
      c6_f_y;
  }

  for (c6_k_k = 0; c6_k_k < 2500; c6_k_k++) {
    c6_m_k = c6_k_k;
    c6_b_i = c6_m_k + 1;
    c6_outputIdx = c6_b_i;
    if (c6_outputIdx <= 37) {
      c6_iLeft = 0;
    } else {
      c6_iLeft = c6_outputIdx - 38;
    }

    c6_ipnf = c6_outputIdx + 37;
    if (c6_ipnf > 2500) {
      c6_iRight = 2500;
    } else {
      c6_iRight = c6_ipnf;
    }

    c6_vlen = c6_iRight - c6_iLeft;
    c6_b_vlen = c6_vlen;
    c6_vstart = c6_iLeft + 1;
    c6_c_vlen = c6_b_vlen;
    c6_b_vstart = c6_vstart;
    if (c6_c_vlen == 0) {
      c6_h_y = 0.0;
    } else {
      c6_d_vlen = c6_c_vlen;
      c6_c_vstart = c6_b_vstart;
      c6_e_vlen = c6_d_vlen;
      c6_d_vstart = c6_c_vstart;
      c6_h_y = c6_sumColumnB(chartInstance, c6_sq_ecg, c6_e_vlen, c6_d_vstart);
    }

    c6_counts = c6_c_vlen;
    c6_i_y = c6_h_y;
    c6_count = c6_counts;
    c6_j_y = c6_i_y / (real_T)c6_count;
    chartInstance->c6_Y[c6_m_k] = c6_j_y;
  }

  for (c6_i25 = 0; c6_i25 < 2500; c6_i25++) {
    c6_sq_ecg[c6_i25] = chartInstance->c6_Y[c6_i25];
  }

  c6_accumulatedData = c6_b_sumColumnB(chartInstance, c6_sq_ecg);
  c6_g_y = c6_accumulatedData / 2500.0;
  c6_threshold = 0.5 * c6_g_y;
  c6_b_st.site = &c6_b_emlrtRSI;
  c6_findpeaks(chartInstance, &c6_b_st, chartInstance->c6_Y, c6_threshold,
               c6_b_pks_data, c6_pks_size, c6_locs_data, c6_locs_size);
  if (covrtEmlIfEval(chartInstance->c6_covrtInstance, 4U, 0, 1,
                     covrtRelationalopUpdateFcn(chartInstance->c6_covrtInstance,
        4U, 0U, 0U, (real_T)c6_locs_size[0], 2.0, -1, 5U, c6_locs_size[0] >= 2)))
  {
    c6_b_st.site = &c6_c_emlrtRSI;
    c6_dimSize = c6_locs_size[0];
    c6_newDimSize = c6_dimSize;
    c6_ySize[0] = (real_T)(c6_newDimSize - 1);
    c6_y1_size[0] = (int32_T)c6_ySize[0];
    c6_b_ixLead = 1;
    c6_b_iyLead = 0;
    c6_work_data[0] = c6_locs_data[0];
    c6_c_st.site = &c6_vb_emlrtRSI;
    c6_h_b = c6_dimSize;
    c6_i_b = c6_h_b;
    if (c6_i_b < 2) {
      c6_overflow = false;
    } else {
      c6_overflow = (c6_i_b > 2147483646);
    }

    if (c6_overflow) {
      c6_d_st.site = &c6_tb_emlrtRSI;
      c6_check_forloop_overflow_error(chartInstance, &c6_d_st);
    }

    for (c6_b_m = 2; c6_b_m <= c6_dimSize; c6_b_m++) {
      c6_b_tmp1 = c6_locs_data[c6_b_ixLead];
      for (c6_n_k = 0; c6_n_k < 1; c6_n_k++) {
        c6_b_tmp2 = c6_work_data[0];
        c6_work_data[0] = c6_b_tmp1;
        c6_b_tmp1 -= c6_b_tmp2;
      }

      c6_b_ixLead++;
      c6_y1_data[c6_b_iyLead] = c6_b_tmp1;
      c6_b_iyLead++;
    }

    c6_b_st.site = &c6_c_emlrtRSI;
    if ((c6_y1_size[0] == 1) || (c6_y1_size[0] != 1)) {
      c6_b3 = true;
    } else {
      c6_b3 = false;
    }

    if (!c6_b3) {
      c6_k_y = NULL;
      sf_mex_assign(&c6_k_y, sf_mex_create("y", c6_cv3, 10, 0U, 1, 0U, 2, 1, 36),
                    false);
      c6_l_y = NULL;
      sf_mex_assign(&c6_l_y, sf_mex_create("y", c6_cv3, 10, 0U, 1, 0U, 2, 1, 36),
                    false);
      sf_mex_call(&c6_b_st, &c6_o_emlrtMCI, "error", 0U, 2U, 14, c6_k_y, 14,
                  sf_mex_call(&c6_b_st, NULL, "getString", 1U, 1U, 14,
        sf_mex_call(&c6_b_st, NULL, "message", 1U, 1U, 14, c6_l_y)));
    }

    c6_f_vlen = c6_y1_size[0];
    c6_g_vlen = c6_f_vlen;
    if ((c6_y1_size[0] == 0) || (c6_g_vlen == 0)) {
      c6_b_accumulatedData = 0.0;
    } else {
      c6_h_vlen = c6_g_vlen;
      c6_i_vlen = c6_h_vlen;
      c6_b_accumulatedData = c6_c_sumColumnB(chartInstance, c6_y1_data,
        c6_i_vlen);
    }

    c6_accumulatedWeights = (real_T)c6_y1_size[0];
    c6_m_y = c6_b_accumulatedData / c6_accumulatedWeights;
    c6_rr = c6_m_y / 500.0;
    c6_current_bpm = 60.0 / c6_rr;
    chartInstance->c6_bpm_val = 0.9 * chartInstance->c6_bpm_val + 0.1 *
      c6_current_bpm;
  }

  c6_b_bpm = chartInstance->c6_bpm_val;
  for (c6_i26 = 0; c6_i26 < 2500; c6_i26++) {
    (*chartInstance->c6_qrs_envelope)[c6_i26] = chartInstance->c6_Y[c6_i26];
  }

  *chartInstance->c6_bpm = c6_b_bpm;
  for (c6_i27 = 0; c6_i27 < 2500; c6_i27++) {
    covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 1U,
                      (*chartInstance->c6_qrs_envelope)[c6_i27]);
  }

  covrtSigUpdateFcn(chartInstance->c6_covrtInstance, 2U, *chartInstance->c6_bpm);
}

static void ext_mode_exec_c6_untitled(SFc6_untitledInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_update_jit_animation_c6_untitled(SFc6_untitledInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c6_do_animation_call_c6_untitled(SFc6_untitledInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c6_untitled(SFc6_untitledInstanceStruct
  *chartInstance)
{
  const mxArray *c6_b_y = NULL;
  const mxArray *c6_c_y = NULL;
  const mxArray *c6_d_y = NULL;
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(3, 1), false);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", chartInstance->c6_bpm, 0, 0U, 0, 0U,
    0), false);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", *chartInstance->c6_qrs_envelope, 0,
    0U, 1, 0U, 2, 2500, 1), false);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  c6_d_y = NULL;
  if (!chartInstance->c6_bpm_val_not_empty) {
    sf_mex_assign(&c6_d_y, sf_mex_create("y", NULL, 0, 0U, 1, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c6_d_y, sf_mex_create("y", &chartInstance->c6_bpm_val, 0, 0U,
      0, 0U, 0), false);
  }

  sf_mex_setcell(c6_y, 2, c6_d_y);
  sf_mex_assign(&c6_st, c6_y, false);
  return c6_st;
}

static void set_sim_state_c6_untitled(SFc6_untitledInstanceStruct *chartInstance,
  const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T c6_dv[2500];
  int32_T c6_i;
  chartInstance->c6_doneDoubleBufferReInit = true;
  c6_u = sf_mex_dup(c6_st);
  *chartInstance->c6_bpm = c6_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 0)), "bpm");
  c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c6_u, 1)),
                        "qrs_envelope", c6_dv);
  for (c6_i = 0; c6_i < 2500; c6_i++) {
    (*chartInstance->c6_qrs_envelope)[c6_i] = c6_dv[c6_i];
  }

  chartInstance->c6_bpm_val = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 2)), "bpm_val", &chartInstance->c6_bpm_val_not_empty);
  sf_mex_destroy(&c6_u);
  sf_mex_destroy(&c6_st);
}

static void c6_introsort(SFc6_untitledInstanceStruct *chartInstance, int32_T
  c6_b_x[10], c6_anonymous_function *c6_cmp, int32_T c6_c_x[10])
{
  c6_anonymous_function c6_b_cmp;
  int32_T c6_i;
  for (c6_i = 0; c6_i < 10; c6_i++) {
    c6_c_x[c6_i] = c6_b_x[c6_i];
  }

  c6_b_cmp = *c6_cmp;
  c6_c_introsort(chartInstance, c6_c_x, &c6_b_cmp);
}

static void c6_insertionsort(SFc6_untitledInstanceStruct *chartInstance, int32_T
  c6_b_x[10], c6_anonymous_function *c6_cmp, int32_T c6_c_x[10])
{
  c6_anonymous_function c6_b_cmp;
  int32_T c6_i;
  for (c6_i = 0; c6_i < 10; c6_i++) {
    c6_c_x[c6_i] = c6_b_x[c6_i];
  }

  c6_b_cmp = *c6_cmp;
  c6_d_insertionsort(chartInstance, c6_c_x, &c6_b_cmp);
}

static void c6_check_forloop_overflow_error(SFc6_untitledInstanceStruct
  *chartInstance, const emlrtStack *c6_sp)
{
  static char_T c6_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c6_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c6_b_y = NULL;
  const mxArray *c6_c_y = NULL;
  const mxArray *c6_y = NULL;
  (void)chartInstance;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_cv, 10, 0U, 1, 0U, 2, 1, 34), false);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_cv, 10, 0U, 1, 0U, 2, 1, 34),
                false);
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_cv1, 10, 0U, 1, 0U, 2, 1, 5),
                false);
  sf_mex_call(c6_sp, &c6_b_emlrtMCI, "error", 0U, 2U, 14, c6_y, 14, sf_mex_call
              (c6_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c6_sp, NULL,
    "message", 1U, 2U, 14, c6_b_y, 14, c6_c_y)));
}

static void c6_warning(SFc6_untitledInstanceStruct *chartInstance, const
  emlrtStack *c6_sp)
{
  static char_T c6_msgID[21] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'i',
    'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't', 'r', 'i', 'x' };

  static char_T c6_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c6_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c6_st;
  const mxArray *c6_b_y = NULL;
  const mxArray *c6_c_y = NULL;
  const mxArray *c6_y = NULL;
  c6_st.prev = c6_sp;
  c6_st.tls = c6_sp->tls;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", c6_cv, 10, 0U, 1, 0U, 2, 1, 7), false);
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_cv1, 10, 0U, 1, 0U, 2, 1, 7),
                false);
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_msgID, 10, 0U, 1, 0U, 2, 1, 21),
                false);
  c6_st.site = &c6_s_emlrtRSI;
  c6_b_feval(chartInstance, &c6_st, c6_y, c6_feval(chartInstance, &c6_st, c6_b_y,
              c6_c_y));
}

static void c6_filter(SFc6_untitledInstanceStruct *chartInstance, const
                      emlrtStack *c6_sp, real_T c6_b[5], real_T c6_a[5], real_T
                      c6_b_x[2524], real_T c6_zi[4], real_T c6_y[2524])
{
  static char_T c6_cv[60] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'f', 'i', 'l', 't', 'e', 'r', '_', 'f', 'i', 'r', 's', 't',
    'E', 'l', 'e', 'm', 'e', 'n', 't', 'O', 'f', 'D', 'e', 'n', 'o', 'm', 'i',
    'n', 'a', 't', 'o', 'r', 'F', 'i', 'l', 't', 'e', 'r', 'N', 'o', 't', 'F',
    'i', 'n', 'i', 't', 'e' };

  static char_T c6_cv1[55] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'f', 'i', 'l', 't', 'e', 'r', '_', 'f', 'i', 'r', 's', 't',
    'E', 'l', 'e', 'm', 'e', 'n', 't', 'O', 'f', 'D', 'e', 'n', 'o', 'm', 'i',
    'n', 'a', 't', 'o', 'r', 'F', 'i', 'l', 't', 'e', 'r', 'Z', 'e', 'r', 'o' };

  const mxArray *c6_b_y = NULL;
  const mxArray *c6_c_y = NULL;
  const mxArray *c6_d_y = NULL;
  const mxArray *c6_e_y = NULL;
  real_T c6_a1;
  real_T c6_as;
  real_T c6_c_x;
  real_T c6_d_x;
  real_T c6_e_x;
  int32_T c6_b_a;
  int32_T c6_b_j;
  int32_T c6_b_k;
  int32_T c6_c_a;
  int32_T c6_c_j;
  int32_T c6_c_k;
  int32_T c6_d_k;
  int32_T c6_e_k;
  int32_T c6_i;
  int32_T c6_i1;
  int32_T c6_j;
  int32_T c6_k;
  int32_T c6_naxpy;
  boolean_T c6_b1;
  boolean_T c6_b_b;
  boolean_T c6_c_b;
  boolean_T c6_d_b;
  boolean_T c6_e_b;
  (void)chartInstance;
  c6_a1 = c6_a[0];
  c6_c_x = c6_a1;
  c6_d_x = c6_c_x;
  c6_b_b = muDoubleScalarIsInf(c6_d_x);
  c6_c_b = !c6_b_b;
  c6_e_x = c6_c_x;
  c6_d_b = muDoubleScalarIsNaN(c6_e_x);
  c6_b1 = !c6_d_b;
  c6_e_b = (c6_c_b && c6_b1);
  if (!c6_e_b) {
    c6_b_y = NULL;
    sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_cv, 10, 0U, 1, 0U, 2, 1, 60),
                  false);
    c6_d_y = NULL;
    sf_mex_assign(&c6_d_y, sf_mex_create("y", c6_cv, 10, 0U, 1, 0U, 2, 1, 60),
                  false);
    sf_mex_call(c6_sp, &c6_c_emlrtMCI, "error", 0U, 2U, 14, c6_b_y, 14,
                sf_mex_call(c6_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c6_sp, NULL, "message", 1U, 1U, 14, c6_d_y)));
  } else if (c6_a1 == 0.0) {
    c6_c_y = NULL;
    sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_cv1, 10, 0U, 1, 0U, 2, 1, 55),
                  false);
    c6_e_y = NULL;
    sf_mex_assign(&c6_e_y, sf_mex_create("y", c6_cv1, 10, 0U, 1, 0U, 2, 1, 55),
                  false);
    sf_mex_call(c6_sp, &c6_d_emlrtMCI, "error", 0U, 2U, 14, c6_c_y, 14,
                sf_mex_call(c6_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c6_sp, NULL, "message", 1U, 1U, 14, c6_e_y)));
  } else if (c6_a1 != 1.0) {
    for (c6_k = 0; c6_k < 5; c6_k++) {
      c6_c_k = c6_k;
      c6_b[c6_c_k] /= c6_a1;
    }

    for (c6_b_k = 0; c6_b_k < 4; c6_b_k++) {
      c6_a[c6_b_k + 1] /= c6_a1;
    }

    c6_a[0] = 1.0;
  }

  for (c6_d_k = 0; c6_d_k < 4; c6_d_k++) {
    c6_c_k = c6_d_k;
    c6_y[c6_c_k] = c6_zi[c6_c_k];
  }

  memset(&c6_y[4], 0, 2520U * sizeof(real_T));
  for (c6_e_k = 0; c6_e_k < 2524; c6_e_k++) {
    c6_c_k = c6_e_k;
    c6_b_a = 2524 - c6_c_k;
    if (c6_b_a < 5) {
      c6_naxpy = c6_b_a;
    } else {
      c6_naxpy = 5;
    }

    c6_as = c6_b_x[c6_c_k];
    c6_i = (uint8_T)c6_naxpy;
    for (c6_j = 0; c6_j < c6_i; c6_j++) {
      c6_b_j = c6_j;
      c6_y[c6_c_k + c6_b_j] += c6_as * c6_b[c6_b_j];
    }

    c6_c_a = 2523 - c6_c_k;
    if (c6_c_a < 4) {
      c6_naxpy = c6_c_a;
    } else {
      c6_naxpy = 4;
    }

    c6_as = -c6_y[c6_c_k];
    c6_i1 = (uint8_T)c6_naxpy;
    for (c6_c_j = 0; c6_c_j < c6_i1; c6_c_j++) {
      c6_b_j = c6_c_j + 1;
      c6_y[c6_c_k + c6_b_j] += c6_as * c6_a[c6_b_j];
    }
  }
}

static real_T c6_sumColumnB(SFc6_untitledInstanceStruct *chartInstance, real_T
  c6_b_x[2500], int32_T c6_vlen, int32_T c6_vstart)
{
  real_T c6_b_y;
  real_T c6_c_y;
  real_T c6_y;
  int32_T c6_a;
  int32_T c6_b_k;
  int32_T c6_b_vlen;
  int32_T c6_b_vstart;
  int32_T c6_c_k;
  int32_T c6_c_vlen;
  int32_T c6_c_vstart;
  int32_T c6_d_k;
  int32_T c6_d_vstart;
  int32_T c6_e_k;
  int32_T c6_e_vstart;
  int32_T c6_f_k;
  int32_T c6_g_k;
  int32_T c6_h_k;
  int32_T c6_i;
  int32_T c6_i1;
  int32_T c6_i_k;
  int32_T c6_inb;
  int32_T c6_k;
  int32_T c6_lidx;
  int32_T c6_nfb;
  int32_T c6_nleft;
  (void)chartInstance;
  if (c6_vlen <= 1024) {
    c6_b_vlen = c6_vlen - 1;
    c6_b_vstart = c6_vstart - 1;
    c6_y = c6_b_x[c6_b_vstart];
    c6_i = c6_b_vlen;
    for (c6_k = 0; c6_k < c6_i; c6_k++) {
      c6_c_k = c6_k;
      c6_y += c6_b_x[(c6_b_vstart + c6_c_k) + 1];
    }
  } else {
    c6_a = c6_vlen;
    c6_nfb = (uint16_T)((uint32_T)(uint16_T)c6_a >> 10);
    c6_inb = c6_nfb << 10;
    c6_c_vstart = c6_vstart - 1;
    c6_y = c6_b_x[c6_c_vstart];
    for (c6_b_k = 0; c6_b_k < 1023; c6_b_k++) {
      c6_e_k = c6_b_k;
      c6_y += c6_b_x[(c6_c_vstart + c6_e_k) + 1];
    }

    for (c6_d_k = 2; c6_d_k <= c6_nfb; c6_d_k++) {
      c6_d_vstart = c6_vstart + 1023;
      c6_b_y = c6_b_x[c6_d_vstart];
      for (c6_f_k = 0; c6_f_k < 1023; c6_f_k++) {
        c6_g_k = c6_f_k;
        c6_b_y += c6_b_x[(c6_d_vstart + c6_g_k) + 1];
      }

      c6_y += c6_b_y;
    }

    if (c6_vlen > c6_inb) {
      c6_nleft = c6_vlen - c6_inb;
      c6_lidx = c6_vstart + c6_inb;
      c6_c_vlen = c6_nleft - 1;
      c6_e_vstart = c6_lidx - 1;
      c6_c_y = c6_b_x[c6_e_vstart];
      c6_i1 = c6_c_vlen;
      for (c6_h_k = 0; c6_h_k < c6_i1; c6_h_k++) {
        c6_i_k = c6_h_k;
        c6_c_y += c6_b_x[(c6_e_vstart + c6_i_k) + 1];
      }

      c6_y += c6_c_y;
    }
  }

  return c6_y;
}

static real_T c6_b_sumColumnB(SFc6_untitledInstanceStruct *chartInstance, real_T
  c6_b_x[2500])
{
  real_T c6_b_y;
  real_T c6_c_y;
  real_T c6_y;
  int32_T c6_b_k;
  int32_T c6_c_k;
  int32_T c6_d_k;
  int32_T c6_e_k;
  int32_T c6_f_k;
  int32_T c6_k;
  (void)chartInstance;
  c6_y = c6_b_x[0];
  for (c6_k = 0; c6_k < 1023; c6_k++) {
    c6_b_k = c6_k;
    c6_y += c6_b_x[c6_b_k + 1];
  }

  c6_b_y = c6_b_x[1024];
  for (c6_c_k = 0; c6_c_k < 1023; c6_c_k++) {
    c6_d_k = c6_c_k;
    c6_b_y += c6_b_x[c6_d_k + 1025];
  }

  c6_y += c6_b_y;
  c6_c_y = c6_b_x[2048];
  for (c6_e_k = 0; c6_e_k < 451; c6_e_k++) {
    c6_f_k = c6_e_k;
    c6_c_y += c6_b_x[c6_f_k + 2049];
  }

  c6_y += c6_c_y;
  return c6_y;
}

static void c6_findpeaks(SFc6_untitledInstanceStruct *chartInstance, const
  emlrtStack *c6_sp, real_T c6_Yin[2500], real_T c6_varargin_2, real_T
  c6_Ypk_data[], int32_T c6_Ypk_size[1], real_T c6_Xpk_data[], int32_T
  c6_Xpk_size[1])
{
  emlrtStack c6_b_st;
  emlrtStack c6_c_st;
  emlrtStack c6_d_st;
  emlrtStack c6_st;
  real_T c6_dv[2];
  real_T c6_a;
  real_T c6_b_a;
  real_T c6_b_jj;
  real_T c6_b_minH;
  real_T c6_b_varargin_2;
  real_T c6_b_x;
  real_T c6_b_y;
  real_T c6_base;
  real_T c6_c_a;
  real_T c6_c_varargin_2;
  real_T c6_c_x;
  real_T c6_c_y;
  real_T c6_d;
  real_T c6_d1;
  real_T c6_d2;
  real_T c6_d_b;
  real_T c6_d_i;
  real_T c6_d_varargin_2;
  real_T c6_d_x;
  real_T c6_d_y;
  real_T c6_e_a;
  real_T c6_e_b;
  real_T c6_e_varargin_2;
  real_T c6_e_x;
  real_T c6_e_y;
  real_T c6_f_a;
  real_T c6_f_b;
  real_T c6_f_x;
  real_T c6_g_a;
  real_T c6_g_b;
  real_T c6_g_x;
  real_T c6_h_a;
  real_T c6_h_x;
  real_T c6_i_b;
  real_T c6_i_x;
  real_T c6_j_b;
  real_T c6_j_x;
  real_T c6_k_b;
  real_T c6_minH;
  real_T c6_pk;
  real_T c6_varargin_1;
  real_T c6_y;
  real_T c6_yk;
  real_T c6_ykfirst;
  int32_T c6_c_data[5000];
  int32_T c6_iPk_data[5000];
  int32_T c6_sortIdx_data[5000];
  int32_T c6_b_iPk_data[2500];
  int32_T c6_fPk_data[2500];
  int32_T c6_iFinite_data[2500];
  int32_T c6_iInfinite_data[2500];
  int32_T c6_iv[2];
  int32_T c6_b_iPk_size[1];
  int32_T c6_b_locs_temp_size[1];
  int32_T c6_c_size[1];
  int32_T c6_fPk_size[1];
  int32_T c6_iFinite_size[1];
  int32_T c6_iInfinite_size[1];
  int32_T c6_iPk_size[1];
  int32_T c6_idelete_size[1];
  int32_T c6_iv1[1];
  int32_T c6_locs_temp_size[1];
  int32_T c6_pks_size[1];
  int32_T c6_sortIdx_size[1];
  int32_T c6_b_i;
  int32_T c6_b_i2;
  int32_T c6_b_idx1;
  int32_T c6_b_idx2;
  int32_T c6_b_j;
  int32_T c6_b_k;
  int32_T c6_b_loop_ub;
  int32_T c6_b_n;
  int32_T c6_b_nPk;
  int32_T c6_b_varargin_1;
  int32_T c6_c;
  int32_T c6_c_i;
  int32_T c6_c_k;
  int32_T c6_c_loop_ub;
  int32_T c6_c_p;
  int32_T c6_c_varargin_1;
  int32_T c6_d_a;
  int32_T c6_d_k;
  int32_T c6_d_loop_ub;
  int32_T c6_d_varargin_1;
  int32_T c6_e_i;
  int32_T c6_e_k;
  int32_T c6_e_loop_ub;
  int32_T c6_e_varargin_1;
  int32_T c6_end;
  int32_T c6_f_i;
  int32_T c6_f_k;
  int32_T c6_f_loop_ub;
  int32_T c6_g_loop_ub;
  int32_T c6_h_loop_ub;
  int32_T c6_i;
  int32_T c6_i1;
  int32_T c6_i10;
  int32_T c6_i11;
  int32_T c6_i12;
  int32_T c6_i13;
  int32_T c6_i14;
  int32_T c6_i15;
  int32_T c6_i16;
  int32_T c6_i17;
  int32_T c6_i18;
  int32_T c6_i19;
  int32_T c6_i2;
  int32_T c6_i20;
  int32_T c6_i21;
  int32_T c6_i22;
  int32_T c6_i23;
  int32_T c6_i24;
  int32_T c6_i25;
  int32_T c6_i26;
  int32_T c6_i27;
  int32_T c6_i28;
  int32_T c6_i29;
  int32_T c6_i3;
  int32_T c6_i30;
  int32_T c6_i31;
  int32_T c6_i4;
  int32_T c6_i5;
  int32_T c6_i6;
  int32_T c6_i7;
  int32_T c6_i8;
  int32_T c6_i9;
  int32_T c6_i_loop_ub;
  int32_T c6_idx1;
  int32_T c6_idx2;
  int32_T c6_j;
  int32_T c6_j_loop_ub;
  int32_T c6_jj;
  int32_T c6_k;
  int32_T c6_kEnd;
  int32_T c6_kfirst;
  int32_T c6_locs_temp;
  int32_T c6_loop_ub;
  int32_T c6_n;
  int32_T c6_nInf;
  int32_T c6_nInflect;
  int32_T c6_nPk;
  int32_T c6_np1;
  int32_T c6_pEnd;
  int32_T c6_partialTrueCount;
  int32_T c6_q;
  int32_T c6_qEnd;
  int32_T c6_trueCount;
  char_T c6_dir;
  char_T c6_previousdir;
  boolean_T c6_idelete_data[5000];
  boolean_T c6_b;
  boolean_T c6_b1;
  boolean_T c6_b2;
  boolean_T c6_b3;
  boolean_T c6_b4;
  boolean_T c6_b5;
  boolean_T c6_b6;
  boolean_T c6_b7;
  boolean_T c6_b8;
  boolean_T c6_b_b;
  boolean_T c6_b_p;
  boolean_T c6_c_b;
  boolean_T c6_d_p;
  boolean_T c6_e_p;
  boolean_T c6_f_p;
  boolean_T c6_g_p;
  boolean_T c6_h_b;
  boolean_T c6_isinfyk;
  boolean_T c6_isinfykfirst;
  boolean_T c6_l_b;
  boolean_T c6_p;
  c6_st.prev = c6_sp;
  c6_st.tls = c6_sp->tls;
  c6_st.site = &c6_w_emlrtRSI;
  c6_b_st.prev = &c6_st;
  c6_b_st.tls = c6_st.tls;
  c6_c_st.prev = &c6_b_st;
  c6_c_st.tls = c6_b_st.tls;
  c6_d_st.prev = &c6_c_st;
  c6_d_st.tls = c6_c_st.tls;
  c6_b_varargin_2 = c6_varargin_2;
  c6_c_varargin_2 = c6_b_varargin_2;
  c6_d_varargin_2 = c6_c_varargin_2;
  c6_minH = c6_d_varargin_2;
  c6_st.site = &c6_x_emlrtRSI;
  c6_nPk = 0;
  c6_nInf = 0;
  c6_nInflect = 0;
  c6_dir = 'n';
  c6_kfirst = 0;
  c6_ykfirst = rtInf;
  c6_isinfykfirst = true;
  for (c6_k = 0; c6_k < 2500; c6_k++) {
    c6_yk = c6_Yin[c6_k];
    c6_b_x = c6_yk;
    c6_b_b = muDoubleScalarIsNaN(c6_b_x);
    if (c6_b_b) {
      c6_yk = rtInf;
      c6_isinfyk = true;
    } else {
      c6_c_x = c6_yk;
      c6_c_b = muDoubleScalarIsInf(c6_c_x);
      if (c6_c_b && (c6_yk > 0.0)) {
        c6_isinfyk = true;
        c6_nInf++;
        if ((c6_nInf < 1) || (c6_nInf > 2500)) {
          emlrtDynamicBoundsCheckR2012b(c6_nInf, 1, 2500, &c6_e_emlrtBCI, &c6_st);
        }

        c6_iInfinite_data[c6_nInf - 1] = c6_k + 1;
      } else {
        c6_isinfyk = false;
      }
    }

    if (c6_yk != c6_ykfirst) {
      c6_previousdir = c6_dir;
      if (c6_isinfyk || c6_isinfykfirst) {
        c6_dir = 'n';
        if (c6_kfirst >= 1) {
          c6_nInflect++;
          if ((c6_nInflect < 1) || (c6_nInflect > 2500)) {
            emlrtDynamicBoundsCheckR2012b(c6_nInflect, 1, 2500, &c6_k_emlrtBCI,
              &c6_st);
          }

          c6_fPk_data[c6_nInflect - 1] = c6_kfirst;
        }
      } else if (c6_yk < c6_ykfirst) {
        c6_dir = 'd';
        if (c6_previousdir != 'd') {
          c6_nInflect++;
          if ((c6_nInflect < 1) || (c6_nInflect > 2500)) {
            emlrtDynamicBoundsCheckR2012b(c6_nInflect, 1, 2500, &c6_j_emlrtBCI,
              &c6_st);
          }

          c6_fPk_data[c6_nInflect - 1] = c6_kfirst;
          if (c6_previousdir == 'i') {
            c6_nPk++;
            if ((c6_nPk < 1) || (c6_nPk > 2500)) {
              emlrtDynamicBoundsCheckR2012b(c6_nPk, 1, 2500, &c6_g_emlrtBCI,
                &c6_st);
            }

            c6_iFinite_data[c6_nPk - 1] = c6_kfirst;
          }
        }
      } else {
        c6_dir = 'i';
        if (c6_previousdir != 'i') {
          c6_nInflect++;
          if ((c6_nInflect < 1) || (c6_nInflect > 2500)) {
            emlrtDynamicBoundsCheckR2012b(c6_nInflect, 1, 2500, &c6_i_emlrtBCI,
              &c6_st);
          }

          c6_fPk_data[c6_nInflect - 1] = c6_kfirst;
        }
      }

      c6_ykfirst = c6_yk;
      c6_kfirst = c6_k + 1;
      c6_isinfykfirst = c6_isinfyk;
    }
  }

  if ((!c6_isinfykfirst) && ((c6_nInflect == 0) || (c6_fPk_data[c6_nInflect - 1]
        < 2500))) {
    c6_nInflect++;
    if ((c6_nInflect < 1) || (c6_nInflect > 2500)) {
      emlrtDynamicBoundsCheckR2012b(c6_nInflect, 1, 2500, &c6_h_emlrtBCI, &c6_st);
    }
  }

  c6_b = (c6_nPk < 1);
  if (c6_b) {
    c6_i = -1;
  } else {
    if ((c6_nPk < 1) || (c6_nPk > 2500)) {
      emlrtDynamicBoundsCheckR2012b(c6_nPk, 1, 2500, &c6_f_emlrtBCI, &c6_st);
    }

    c6_i = c6_nPk - 1;
  }

  c6_iFinite_size[0] = c6_i + 1;
  c6_b1 = (c6_nInf < 1);
  if (c6_b1) {
    c6_i1 = -1;
  } else {
    if ((c6_nInf < 1) || (c6_nInf > 2500)) {
      emlrtDynamicBoundsCheckR2012b(c6_nInf, 1, 2500, &c6_d_emlrtBCI, &c6_st);
    }

    c6_i1 = c6_nInf - 1;
  }

  c6_iInfinite_size[0] = c6_i1 + 1;
  c6_b2 = (c6_nInflect < 1);
  if ((!c6_b2) && ((c6_nInflect < 1) || (c6_nInflect > 2500))) {
    emlrtDynamicBoundsCheckR2012b(c6_nInflect, 1, 2500, &c6_c_emlrtBCI, &c6_st);
  }

  c6_st.site = &c6_y_emlrtRSI;
  c6_b_minH = c6_minH;
  c6_iPk_size[0] = c6_iFinite_size[0];
  c6_b_nPk = 0;
  c6_n = c6_iFinite_size[0];
  c6_i2 = (uint16_T)c6_n;
  for (c6_b_k = 0; c6_b_k < c6_i2; c6_b_k++) {
    c6_c_k = c6_b_k;
    c6_i3 = c6_c_k + 1;
    if ((c6_i3 < 1) || (c6_i3 > c6_iFinite_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c6_i3, 1, c6_iFinite_size[0], &c6_n_emlrtBCI,
        &c6_st);
    }

    c6_j = c6_iFinite_data[c6_i3 - 1];
    if ((c6_j < 1) || (c6_j > 2500)) {
      emlrtDynamicBoundsCheckR2012b(c6_j, 1, 2500, &c6_o_emlrtBCI, &c6_st);
    }

    c6_pk = c6_Yin[c6_j - 1];
    if (c6_pk > c6_b_minH) {
      c6_i6 = c6_j - 1;
      if ((c6_i6 < 1) || (c6_i6 > 2500)) {
        emlrtDynamicBoundsCheckR2012b(c6_i6, 1, 2500, &c6_p_emlrtBCI, &c6_st);
      }

      c6_varargin_1 = c6_Yin[c6_i6 - 1];
      c6_i8 = c6_j + 1;
      if ((c6_i8 < 1) || (c6_i8 > 2500)) {
        emlrtDynamicBoundsCheckR2012b(c6_i8, 1, 2500, &c6_q_emlrtBCI, &c6_st);
      }

      c6_e_varargin_2 = c6_Yin[c6_i8 - 1];
      c6_d_x = c6_varargin_1;
      c6_y = c6_e_varargin_2;
      c6_e_x = c6_d_x;
      c6_b_y = c6_y;
      c6_f_x = c6_e_x;
      c6_c_y = c6_b_y;
      c6_a = c6_f_x;
      c6_d_b = c6_c_y;
      c6_g_x = c6_a;
      c6_d_y = c6_d_b;
      c6_h_x = c6_g_x;
      c6_e_y = c6_d_y;
      c6_base = muDoubleScalarMax(c6_h_x, c6_e_y);
      if (c6_pk - c6_base >= 0.0) {
        c6_b_nPk++;
        if ((c6_b_nPk < 1) || (c6_b_nPk > c6_iPk_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c6_b_nPk, 1, c6_iPk_size[0],
            &c6_r_emlrtBCI, &c6_st);
        }

        c6_b_iPk_data[c6_b_nPk - 1] = c6_j;
      }
    }
  }

  c6_b3 = (c6_b_nPk < 1);
  if (c6_b3) {
    c6_i4 = 0;
  } else {
    if (c6_iPk_size[0] < 1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, c6_iPk_size[0], &c6_b_emlrtBCI, &c6_st);
    }

    if ((c6_b_nPk < 1) || (c6_b_nPk > c6_iPk_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c6_b_nPk, 1, c6_iPk_size[0], &c6_emlrtBCI,
        &c6_st);
    }

    c6_i4 = c6_b_nPk;
  }

  c6_iPk_size[0] = c6_i4;
  c6_b_iPk_size[0] = c6_iPk_size[0];
  c6_loop_ub = c6_iPk_size[0] - 1;
  for (c6_i5 = 0; c6_i5 <= c6_loop_ub; c6_i5++) {
    c6_iPk_data[c6_i5] = c6_b_iPk_data[c6_i5];
  }

  c6_st.site = &c6_ab_emlrtRSI;
  c6_iPk_size[0] = c6_b_iPk_size[0];
  c6_b_loop_ub = c6_b_iPk_size[0] - 1;
  for (c6_i7 = 0; c6_i7 <= c6_b_loop_ub; c6_i7++) {
    c6_b_iPk_data[c6_i7] = c6_iPk_data[c6_i7];
  }

  c6_b_st.site = &c6_eb_emlrtRSI;
  c6_c_st.site = &c6_fb_emlrtRSI;
  c6_d_st.site = &c6_gb_emlrtRSI;
  c6_do_vectors(chartInstance, &c6_d_st, c6_b_iPk_data, c6_iPk_size,
                c6_iInfinite_data, c6_iInfinite_size, c6_c_data, c6_c_size,
                c6_fPk_data, c6_fPk_size, c6_iFinite_data, c6_iFinite_size);
  c6_st.site = &c6_bb_emlrtRSI;
  if (c6_c_size[0] == 0) {
    c6_b_st.site = &c6_hb_emlrtRSI;
    c6_c_st.site = &c6_jb_emlrtRSI;
    c6_b_iPk_size[0] = 0;
  } else {
    c6_pks_size[0] = c6_c_size[0];
    c6_c_loop_ub = c6_c_size[0] - 1;
    for (c6_i9 = 0; c6_i9 <= c6_c_loop_ub; c6_i9++) {
      chartInstance->c6_pks_data[c6_i9] = c6_Yin[c6_c_data[c6_i9] - 1];
    }

    c6_locs_temp_size[0] = c6_c_size[0];
    c6_d_loop_ub = c6_c_size[0] - 1;
    for (c6_i10 = 0; c6_i10 <= c6_d_loop_ub; c6_i10++) {
      chartInstance->c6_locs_temp_data[c6_i10] = 1.0 + (real_T)(c6_c_data[c6_i10]
        - 1);
    }

    c6_sortIdx_size[0] = c6_pks_size[0];
    c6_b_n = c6_pks_size[0];
    c6_np1 = c6_b_n + 1;
    c6_i11 = c6_b_n;
    for (c6_d_k = 1; c6_d_k <= c6_i11 - 1; c6_d_k += 2) {
      c6_idx1 = c6_d_k - 1;
      c6_idx2 = c6_d_k;
      c6_b_a = chartInstance->c6_pks_data[c6_idx1];
      c6_e_b = chartInstance->c6_pks_data[c6_idx2];
      c6_c_a = c6_b_a;
      c6_f_b = c6_e_b;
      c6_e_a = c6_c_a;
      c6_g_b = c6_f_b;
      c6_p = (c6_e_a >= c6_g_b);
      if (c6_p) {
        c6_b_p = true;
      } else {
        c6_i_x = c6_c_a;
        c6_h_b = muDoubleScalarIsNaN(c6_i_x);
        if (c6_h_b) {
          c6_b_p = true;
        } else {
          c6_b_p = false;
        }
      }

      c6_d_p = c6_b_p;
      if (c6_d_p) {
        c6_sortIdx_data[c6_d_k - 1] = c6_d_k;
        c6_sortIdx_data[c6_d_k] = c6_d_k + 1;
      } else {
        c6_sortIdx_data[c6_d_k - 1] = c6_d_k + 1;
        c6_sortIdx_data[c6_d_k] = c6_d_k;
      }
    }

    if ((c6_b_n & 1) != 0) {
      c6_sortIdx_data[c6_b_n - 1] = c6_b_n;
    }

    c6_b_i = 2;
    while (c6_b_i < c6_b_n) {
      c6_d_a = c6_b_i;
      c6_b_i2 = c6_d_a << 1;
      c6_b_j = 1;
      for (c6_pEnd = 1 + c6_b_i; c6_pEnd < c6_np1; c6_pEnd = c6_qEnd + c6_b_i) {
        c6_c_p = c6_b_j - 1;
        c6_q = c6_pEnd - 1;
        c6_qEnd = c6_b_j + c6_b_i2;
        if (c6_qEnd > c6_np1) {
          c6_qEnd = c6_np1;
        }

        c6_e_k = 0;
        c6_kEnd = c6_qEnd - c6_b_j;
        while (c6_e_k + 1 <= c6_kEnd) {
          c6_b_idx1 = c6_sortIdx_data[c6_c_p] - 1;
          c6_b_idx2 = c6_sortIdx_data[c6_q] - 1;
          c6_f_a = chartInstance->c6_pks_data[c6_b_idx1];
          c6_i_b = chartInstance->c6_pks_data[c6_b_idx2];
          c6_g_a = c6_f_a;
          c6_j_b = c6_i_b;
          c6_h_a = c6_g_a;
          c6_k_b = c6_j_b;
          c6_e_p = (c6_h_a >= c6_k_b);
          if (c6_e_p) {
            c6_f_p = true;
          } else {
            c6_j_x = c6_g_a;
            c6_l_b = muDoubleScalarIsNaN(c6_j_x);
            if (c6_l_b) {
              c6_f_p = true;
            } else {
              c6_f_p = false;
            }
          }

          c6_g_p = c6_f_p;
          if (c6_g_p) {
            c6_iPk_data[c6_e_k] = c6_sortIdx_data[c6_c_p];
            c6_c_p++;
            if (c6_c_p + 1 == c6_pEnd) {
              while (c6_q + 1 < c6_qEnd) {
                c6_e_k++;
                c6_iPk_data[c6_e_k] = c6_sortIdx_data[c6_q];
                c6_q++;
              }
            }
          } else {
            c6_iPk_data[c6_e_k] = c6_sortIdx_data[c6_q];
            c6_q++;
            if (c6_q + 1 == c6_qEnd) {
              while (c6_c_p + 1 < c6_pEnd) {
                c6_e_k++;
                c6_iPk_data[c6_e_k] = c6_sortIdx_data[c6_c_p];
                c6_c_p++;
              }
            }
          }

          c6_e_k++;
        }

        c6_c_p = c6_b_j - 2;
        for (c6_f_k = 0; c6_f_k < c6_kEnd; c6_f_k++) {
          c6_e_k = c6_f_k;
          c6_sortIdx_data[(c6_c_p + c6_e_k) + 1] = c6_iPk_data[c6_e_k];
        }

        c6_b_j = c6_qEnd;
      }

      c6_b_i = c6_b_i2;
    }

    c6_locs_temp = c6_locs_temp_size[0];
    c6_b_locs_temp_size[0] = c6_sortIdx_size[0];
    c6_f_loop_ub = c6_sortIdx_size[0] - 1;
    for (c6_i16 = 0; c6_i16 <= c6_f_loop_ub; c6_i16++) {
      if ((c6_sortIdx_data[c6_i16] < 1) || (c6_sortIdx_data[c6_i16] >
           c6_locs_temp)) {
        emlrtDynamicBoundsCheckR2012b(c6_sortIdx_data[c6_i16], 1, c6_locs_temp,
          &c6_s_emlrtBCI, &c6_st);
      }

      chartInstance->c6_b_locs_temp_data[c6_i16] =
        chartInstance->c6_locs_temp_data[c6_sortIdx_data[c6_i16] - 1];
    }

    c6_locs_temp_size[0] = c6_b_locs_temp_size[0];
    c6_h_loop_ub = c6_b_locs_temp_size[0] - 1;
    for (c6_i18 = 0; c6_i18 <= c6_h_loop_ub; c6_i18++) {
      chartInstance->c6_locs_temp_data[c6_i18] =
        chartInstance->c6_b_locs_temp_data[c6_i18];
    }

    c6_dv[0] = (real_T)c6_locs_temp_size[0];
    c6_idelete_size[0] = (int32_T)c6_dv[0];
    c6_j_loop_ub = (int32_T)c6_dv[0] - 1;
    if (c6_j_loop_ub >= 0) {
      memset(&c6_idelete_data[0], 0, (uint32_T)(c6_j_loop_ub + 1) * sizeof
             (boolean_T));
    }

    c6_iv1[0] = (int32_T)c6_dv[0];
    c6_b_varargin_1 = c6_iv1[0];
    c6_c_varargin_1 = c6_b_varargin_1;
    c6_d1 = (real_T)c6_c_varargin_1;
    c6_i20 = (int32_T)c6_d1;
    for (c6_c_i = 0; c6_c_i < c6_i20; c6_c_i++) {
      c6_d_i = (real_T)c6_c_i + 1.0;
      c6_i21 = (int32_T)c6_d_i;
      if ((c6_i21 < 1) || (c6_i21 > c6_idelete_size[0])) {
        emlrtDynamicBoundsCheckR2012b(c6_i21, 1, c6_idelete_size[0],
          &c6_u_emlrtBCI, &c6_st);
      }

      if (!c6_idelete_data[c6_i21 - 1]) {
        c6_d_varargin_1 = c6_idelete_size[0];
        c6_e_varargin_1 = c6_d_varargin_1;
        c6_d2 = (real_T)c6_e_varargin_1;
        c6_i22 = (int32_T)-((-1.0 - c6_d2) + 1.0);
        emlrtForLoopVectorCheckR2021a(c6_d2, -1.0, 1.0, mxDOUBLE_CLASS, c6_i22,
          &c6_rb_emlrtRTEI, &c6_st);
        for (c6_jj = 0; c6_jj < c6_i22; c6_jj++) {
          c6_b_jj = c6_d2 - (real_T)c6_jj;
          c6_i26 = (int32_T)c6_b_jj;
          if ((c6_i26 < 1) || (c6_i26 > c6_idelete_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c6_i26, 1, c6_idelete_size[0],
              &c6_x_emlrtBCI, &c6_st);
          }

          c6_b5 = c6_idelete_data[c6_i26 - 1];
          c6_i27 = (int32_T)c6_b_jj;
          if ((c6_i27 < 1) || (c6_i27 > c6_locs_temp_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c6_i27, 1, c6_locs_temp_size[0],
              &c6_y_emlrtBCI, &c6_st);
          }

          c6_i28 = (int32_T)c6_d_i;
          if ((c6_i28 < 1) || (c6_i28 > c6_locs_temp_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c6_i28, 1, c6_locs_temp_size[0],
              &c6_ab_emlrtBCI, &c6_st);
          }

          c6_b6 = (chartInstance->c6_locs_temp_data[c6_i27 - 1] >=
                   chartInstance->c6_locs_temp_data[c6_i28 - 1] - 200.0);
          c6_i29 = (int32_T)c6_b_jj;
          if ((c6_i29 < 1) || (c6_i29 > c6_locs_temp_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c6_i29, 1, c6_locs_temp_size[0],
              &c6_bb_emlrtBCI, &c6_st);
          }

          c6_i30 = (int32_T)c6_d_i;
          if ((c6_i30 < 1) || (c6_i30 > c6_locs_temp_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c6_i30, 1, c6_locs_temp_size[0],
              &c6_cb_emlrtBCI, &c6_st);
          }

          c6_b7 = (chartInstance->c6_locs_temp_data[c6_i29 - 1] <=
                   chartInstance->c6_locs_temp_data[c6_i30 - 1] + 200.0);
          c6_b8 = (c6_b6 && c6_b7);
          c6_i31 = (int32_T)c6_b_jj;
          if ((c6_i31 < 1) || (c6_i31 > c6_idelete_size[0])) {
            emlrtDynamicBoundsCheckR2012b(c6_i31, 1, c6_idelete_size[0],
              &c6_db_emlrtBCI, &c6_st);
          }

          c6_idelete_data[c6_i31 - 1] = (c6_b5 || c6_b8);
        }

        c6_i25 = (int32_T)c6_d_i;
        if ((c6_i25 < 1) || (c6_i25 > c6_idelete_size[0])) {
          emlrtDynamicBoundsCheckR2012b(c6_i25, 1, c6_idelete_size[0],
            &c6_w_emlrtBCI, &c6_st);
        }

        c6_idelete_data[c6_i25 - 1] = false;
      }
    }

    c6_end = c6_idelete_size[0];
    c6_trueCount = 0;
    for (c6_e_i = 0; c6_e_i < c6_end; c6_e_i++) {
      if (!c6_idelete_data[c6_e_i]) {
        c6_trueCount++;
      }
    }

    c6_b_iPk_size[0] = c6_trueCount;
    c6_partialTrueCount = 0;
    for (c6_f_i = 0; c6_f_i < c6_end; c6_f_i++) {
      if (!c6_idelete_data[c6_f_i]) {
        c6_i24 = c6_sortIdx_size[0] - 1;
        if ((c6_f_i < 0) || (c6_f_i > c6_i24)) {
          emlrtDynamicBoundsCheckR2012b(c6_f_i, 0, c6_i24, &c6_v_emlrtBCI,
            &c6_st);
        }

        c6_iPk_data[c6_partialTrueCount] = c6_sortIdx_data[c6_f_i];
        c6_partialTrueCount++;
      }
    }

    if (c6_b_iPk_size[0] == 0) {
    } else {
      c6_i23 = c6_b_iPk_size[0];
      c6_b_st.site = &c6_ib_emlrtRSI;
      c6_d_introsort(chartInstance, &c6_b_st, c6_iPk_data, c6_i23);
    }
  }

  if (c6_b_iPk_size[0] > 2500) {
    c6_fPk_size[0] = 2500;
    c6_st.site = &c6_cb_emlrtRSI;
    c6_indexShapeCheck(chartInstance);
    c6_b_iPk_size[0] = 2500;
  } else {
    c6_dv[0] = (real_T)c6_b_iPk_size[0];
    c6_fPk_size[0] = (int32_T)c6_dv[0];
  }

  c6_d = (real_T)c6_fPk_size[0];
  c6_b4 = (c6_d < 1.0);
  if (c6_b4) {
    c6_i13 = 0;
  } else {
    c6_i12 = 1;
    if ((c6_i12 < 1) || (c6_i12 > c6_b_iPk_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c6_i12, 1, c6_b_iPk_size[0], &c6_m_emlrtBCI,
        (emlrtConstCTX)c6_sp);
    }

    c6_i14 = (int32_T)c6_d;
    if ((c6_i14 < 1) || (c6_i14 > c6_b_iPk_size[0])) {
      emlrtDynamicBoundsCheckR2012b(c6_i14, 1, c6_b_iPk_size[0], &c6_l_emlrtBCI,
        (emlrtConstCTX)c6_sp);
    }

    c6_i13 = c6_i14;
  }

  c6_iv[0] = 1;
  c6_iv[1] = c6_i13;
  c6_st.site = &c6_db_emlrtRSI;
  c6_b_indexShapeCheck(chartInstance, &c6_st, c6_b_iPk_size[0], c6_iv);
  c6_c = c6_c_size[0];
  c6_fPk_size[0] = c6_i13;
  c6_e_loop_ub = c6_i13 - 1;
  for (c6_i15 = 0; c6_i15 <= c6_e_loop_ub; c6_i15++) {
    if ((c6_iPk_data[c6_i15] < 1) || (c6_iPk_data[c6_i15] > c6_c)) {
      emlrtDynamicBoundsCheckR2012b(c6_iPk_data[c6_i15], 1, c6_c, &c6_t_emlrtBCI,
        (emlrtConstCTX)c6_sp);
    }

    c6_fPk_data[c6_i15] = c6_c_data[c6_iPk_data[c6_i15] - 1];
  }

  c6_Ypk_size[0] = c6_fPk_size[0];
  c6_g_loop_ub = c6_fPk_size[0] - 1;
  for (c6_i17 = 0; c6_i17 <= c6_g_loop_ub; c6_i17++) {
    c6_Ypk_data[c6_i17] = c6_Yin[c6_fPk_data[c6_i17] - 1];
  }

  c6_Xpk_size[0] = c6_fPk_size[0];
  c6_i_loop_ub = c6_fPk_size[0] - 1;
  for (c6_i19 = 0; c6_i19 <= c6_i_loop_ub; c6_i19++) {
    c6_Xpk_data[c6_i19] = 1.0 + (real_T)(c6_fPk_data[c6_i19] - 1);
  }
}

static void c6_do_vectors(SFc6_untitledInstanceStruct *chartInstance, const
  emlrtStack *c6_sp, int32_T c6_a_data[], int32_T c6_a_size[1], int32_T
  c6_b_data[], int32_T c6_b_size[1], int32_T c6_c_data[], int32_T c6_c_size[1],
  int32_T c6_ia_data[], int32_T c6_ia_size[1], int32_T c6_ib_data[], int32_T
  c6_ib_size[1])
{
  static char_T c6_cv[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 's', 'e', 't', 'o', 'p', '_', 'u',
    'n', 's', 'o', 'r', 't', 'e', 'd', 'A' };

  static char_T c6_cv1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'e', 'm', 'l', '_', 's', 'e', 't', 'o', 'p', '_', 'u',
    'n', 's', 'o', 'r', 't', 'e', 'd', 'B' };

  static char_T c6_cv2[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'b', 'u', 'i', 'l',
    't', 'i', 'n', 's', ':', 'A', 's', 's', 'e', 'r', 't', 'i', 'o', 'n', 'F',
    'a', 'i', 'l', 'e', 'd' };

  const mxArray *c6_b_y = NULL;
  const mxArray *c6_c_y = NULL;
  const mxArray *c6_d_y = NULL;
  const mxArray *c6_e_y = NULL;
  const mxArray *c6_f_y = NULL;
  const mxArray *c6_g_y = NULL;
  const mxArray *c6_h_y = NULL;
  const mxArray *c6_i_y = NULL;
  const mxArray *c6_j_y = NULL;
  const mxArray *c6_y = NULL;
  int32_T c6_iv[2];
  int32_T c6_a;
  int32_T c6_ab_a;
  int32_T c6_ak;
  int32_T c6_b;
  int32_T c6_b_a;
  int32_T c6_b_ak;
  int32_T c6_b_bk;
  int32_T c6_b_c;
  int32_T c6_b_ialast;
  int32_T c6_b_iblast;
  int32_T c6_b_k;
  int32_T c6_b_nx;
  int32_T c6_b_xkplus;
  int32_T c6_bb_a;
  int32_T c6_bk;
  int32_T c6_c;
  int32_T c6_c_a;
  int32_T c6_c_b;
  int32_T c6_c_c;
  int32_T c6_c_ialast;
  int32_T c6_c_iblast;
  int32_T c6_c_k;
  int32_T c6_c_nx;
  int32_T c6_c_xkplus;
  int32_T c6_cb_a;
  int32_T c6_d_a;
  int32_T c6_d_b;
  int32_T c6_d_c;
  int32_T c6_d_k;
  int32_T c6_d_nx;
  int32_T c6_d_xkplus;
  int32_T c6_db_a;
  int32_T c6_e_a;
  int32_T c6_e_b;
  int32_T c6_eb_a;
  int32_T c6_f_a;
  int32_T c6_f_b;
  int32_T c6_fb_a;
  int32_T c6_g_a;
  int32_T c6_g_b;
  int32_T c6_gb_a;
  int32_T c6_h_a;
  int32_T c6_h_b;
  int32_T c6_i;
  int32_T c6_i1;
  int32_T c6_i2;
  int32_T c6_i_a;
  int32_T c6_i_b;
  int32_T c6_iafirst;
  int32_T c6_ialast;
  int32_T c6_ibfirst;
  int32_T c6_iblast;
  int32_T c6_j_a;
  int32_T c6_k;
  int32_T c6_k_a;
  int32_T c6_l_a;
  int32_T c6_m_a;
  int32_T c6_n_a;
  int32_T c6_na;
  int32_T c6_nb;
  int32_T c6_nc;
  int32_T c6_ncmax;
  int32_T c6_nia;
  int32_T c6_nib;
  int32_T c6_nx;
  int32_T c6_o_a;
  int32_T c6_p_a;
  int32_T c6_q_a;
  int32_T c6_r_a;
  int32_T c6_s_a;
  int32_T c6_t_a;
  int32_T c6_u_a;
  int32_T c6_v_a;
  int32_T c6_w_a;
  int32_T c6_x_a;
  int32_T c6_xkplus;
  int32_T c6_y_a;
  boolean_T c6_b1;
  boolean_T c6_b2;
  boolean_T c6_b_b;
  boolean_T c6_b_p;
  boolean_T c6_c_p;
  boolean_T c6_d_p;
  boolean_T c6_e_p;
  boolean_T c6_exitg1;
  boolean_T c6_f_p;
  boolean_T c6_p;
  c6_na = c6_a_size[0];
  c6_nb = c6_b_size[0];
  c6_a = c6_na;
  c6_b = c6_nb;
  c6_ncmax = c6_a + c6_b;
  c6_iv[0] = c6_ncmax;
  c6_c_size[0] = c6_iv[0];
  c6_ia_size[0] = c6_na;
  c6_ib_size[0] = c6_nb;
  if (!c6_issorted(chartInstance, c6_a_data, c6_a_size)) {
    c6_y = NULL;
    sf_mex_assign(&c6_y, sf_mex_create("y", c6_cv, 10, 0U, 1, 0U, 2, 1, 33),
                  false);
    c6_c_y = NULL;
    sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_cv, 10, 0U, 1, 0U, 2, 1, 33),
                  false);
    sf_mex_call(c6_sp, &c6_e_emlrtMCI, "error", 0U, 2U, 14, c6_y, 14,
                sf_mex_call(c6_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c6_sp, NULL, "message", 1U, 1U, 14, c6_c_y)));
  }

  if (!c6_issorted(chartInstance, c6_b_data, c6_b_size)) {
    c6_b_y = NULL;
    sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_cv1, 10, 0U, 1, 0U, 2, 1, 33),
                  false);
    c6_d_y = NULL;
    sf_mex_assign(&c6_d_y, sf_mex_create("y", c6_cv1, 10, 0U, 1, 0U, 2, 1, 33),
                  false);
    sf_mex_call(c6_sp, &c6_f_emlrtMCI, "error", 0U, 2U, 14, c6_b_y, 14,
                sf_mex_call(c6_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c6_sp, NULL, "message", 1U, 1U, 14, c6_d_y)));
  }

  c6_nc = -1;
  c6_nia = -1;
  c6_nib = 0;
  c6_iafirst = 1;
  c6_ialast = 1;
  c6_ibfirst = 1;
  c6_iblast = 1;
  while ((c6_ialast <= c6_na) && (c6_iblast <= c6_nb)) {
    c6_k = c6_ialast;
    c6_b_ialast = c6_k;
    c6_nx = c6_a_size[0];
    c6_ak = c6_a_data[c6_b_ialast - 1];
    c6_exitg1 = false;
    while ((!c6_exitg1) && (c6_b_ialast < c6_nx)) {
      c6_b_a = c6_b_ialast + 1;
      c6_c = c6_b_a - 1;
      c6_xkplus = c6_a_data[c6_c];
      c6_e_a = c6_xkplus;
      c6_c_b = c6_ak;
      c6_p = (c6_e_a == c6_c_b);
      if (c6_p) {
        c6_l_a = c6_b_ialast + 1;
        c6_b_ialast = c6_l_a;
      } else {
        c6_exitg1 = true;
      }
    }

    c6_ialast = c6_b_ialast;
    c6_d_k = c6_iblast;
    c6_c_iblast = c6_d_k;
    c6_d_nx = c6_b_size[0];
    c6_b_bk = c6_b_data[c6_c_iblast - 1];
    c6_exitg1 = false;
    while ((!c6_exitg1) && (c6_c_iblast < c6_d_nx)) {
      c6_n_a = c6_c_iblast + 1;
      c6_d_c = c6_n_a - 1;
      c6_d_xkplus = c6_b_data[c6_d_c];
      c6_s_a = c6_d_xkplus;
      c6_g_b = c6_b_bk;
      c6_e_p = (c6_s_a == c6_g_b);
      if (c6_e_p) {
        c6_w_a = c6_c_iblast + 1;
        c6_c_iblast = c6_w_a;
      } else {
        c6_exitg1 = true;
      }
    }

    c6_iblast = c6_c_iblast;
    c6_p_a = c6_ak;
    c6_f_b = c6_b_bk;
    c6_d_p = (c6_p_a == c6_f_b);
    if (c6_d_p) {
      c6_u_a = c6_nc + 1;
      c6_nc = c6_u_a;
      c6_c_data[c6_nc] = c6_ak;
      c6_x_a = c6_nia + 1;
      c6_nia = c6_x_a;
      c6_ia_data[c6_nia] = c6_iafirst;
      c6_bb_a = c6_b_ialast + 1;
      c6_ialast = c6_bb_a;
      c6_iafirst = c6_ialast;
      c6_eb_a = c6_c_iblast + 1;
      c6_iblast = c6_eb_a;
      c6_ibfirst = c6_iblast;
    } else {
      c6_t_a = c6_ak;
      c6_h_b = c6_b_bk;
      c6_v_a = c6_t_a;
      c6_i_b = c6_h_b;
      c6_f_p = (c6_v_a < c6_i_b);
      if (c6_f_p) {
        c6_ab_a = c6_nc + 1;
        c6_nc = c6_ab_a;
        c6_db_a = c6_nia + 1;
        c6_nia = c6_db_a;
        c6_c_data[c6_nc] = c6_ak;
        c6_ia_data[c6_nia] = c6_iafirst;
        c6_gb_a = c6_b_ialast + 1;
        c6_ialast = c6_gb_a;
        c6_iafirst = c6_ialast;
      } else {
        c6_y_a = c6_nc + 1;
        c6_nc = c6_y_a;
        c6_cb_a = c6_nib + 1;
        c6_nib = c6_cb_a;
        c6_c_data[c6_nc] = c6_b_bk;
        c6_ib_data[c6_nib - 1] = c6_ibfirst;
        c6_fb_a = c6_c_iblast + 1;
        c6_iblast = c6_fb_a;
        c6_ibfirst = c6_iblast;
      }
    }
  }

  while (c6_ialast <= c6_na) {
    c6_b_k = c6_ialast;
    c6_c_ialast = c6_b_k;
    c6_b_nx = c6_a_size[0];
    c6_b_ak = c6_a_data[c6_c_ialast - 1];
    c6_exitg1 = false;
    while ((!c6_exitg1) && (c6_c_ialast < c6_b_nx)) {
      c6_d_a = c6_c_ialast + 1;
      c6_b_c = c6_d_a - 1;
      c6_b_xkplus = c6_a_data[c6_b_c];
      c6_i_a = c6_b_xkplus;
      c6_d_b = c6_b_ak;
      c6_b_p = (c6_i_a == c6_d_b);
      if (c6_b_p) {
        c6_o_a = c6_c_ialast + 1;
        c6_c_ialast = c6_o_a;
      } else {
        c6_exitg1 = true;
      }
    }

    c6_c_a = c6_nc + 1;
    c6_nc = c6_c_a;
    c6_h_a = c6_nia + 1;
    c6_nia = c6_h_a;
    c6_c_data[c6_nc] = c6_b_ak;
    c6_ia_data[c6_nia] = c6_iafirst;
    c6_m_a = c6_c_ialast + 1;
    c6_ialast = c6_m_a;
    c6_iafirst = c6_ialast;
  }

  while (c6_iblast <= c6_nb) {
    c6_c_k = c6_iblast;
    c6_b_iblast = c6_c_k;
    c6_c_nx = c6_b_size[0];
    c6_bk = c6_b_data[c6_b_iblast - 1];
    c6_exitg1 = false;
    while ((!c6_exitg1) && (c6_b_iblast < c6_c_nx)) {
      c6_g_a = c6_b_iblast + 1;
      c6_c_c = c6_g_a - 1;
      c6_c_xkplus = c6_b_data[c6_c_c];
      c6_k_a = c6_c_xkplus;
      c6_e_b = c6_bk;
      c6_c_p = (c6_k_a == c6_e_b);
      if (c6_c_p) {
        c6_r_a = c6_b_iblast + 1;
        c6_b_iblast = c6_r_a;
      } else {
        c6_exitg1 = true;
      }
    }

    c6_f_a = c6_nc + 1;
    c6_nc = c6_f_a;
    c6_j_a = c6_nib + 1;
    c6_nib = c6_j_a;
    c6_c_data[c6_nc] = c6_bk;
    c6_ib_data[c6_nib - 1] = c6_ibfirst;
    c6_q_a = c6_b_iblast + 1;
    c6_iblast = c6_q_a;
    c6_ibfirst = c6_iblast;
  }

  if (c6_na > 0) {
    if (c6_nia + 1 > c6_na) {
      c6_e_y = NULL;
      sf_mex_assign(&c6_e_y, sf_mex_create("y", c6_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c6_g_y = NULL;
      sf_mex_assign(&c6_g_y, sf_mex_create("y", c6_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      sf_mex_call(c6_sp, &c6_g_emlrtMCI, "error", 0U, 2U, 14, c6_e_y, 14,
                  sf_mex_call(c6_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c6_sp, NULL, "message", 1U, 1U, 14, c6_g_y)));
    }

    c6_b_b = (c6_nia + 1 < 1);
    if (c6_b_b) {
      c6_i = 0;
    } else {
      c6_i = c6_nia + 1;
    }

    c6_ia_size[0] = c6_i;
  }

  if (c6_nb > 0) {
    if (c6_nib > c6_nb) {
      c6_f_y = NULL;
      sf_mex_assign(&c6_f_y, sf_mex_create("y", c6_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c6_i_y = NULL;
      sf_mex_assign(&c6_i_y, sf_mex_create("y", c6_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      sf_mex_call(c6_sp, &c6_h_emlrtMCI, "error", 0U, 2U, 14, c6_f_y, 14,
                  sf_mex_call(c6_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c6_sp, NULL, "message", 1U, 1U, 14, c6_i_y)));
    }

    c6_b1 = (c6_nib < 1);
    if (c6_b1) {
      c6_i1 = 0;
    } else {
      c6_i1 = c6_nib;
    }

    c6_ib_size[0] = c6_i1;
  }

  if (c6_ncmax > 0) {
    if (c6_nc + 1 > c6_ncmax) {
      c6_h_y = NULL;
      sf_mex_assign(&c6_h_y, sf_mex_create("y", c6_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      c6_j_y = NULL;
      sf_mex_assign(&c6_j_y, sf_mex_create("y", c6_cv2, 10, 0U, 1, 0U, 2, 1, 30),
                    false);
      sf_mex_call(c6_sp, &c6_i_emlrtMCI, "error", 0U, 2U, 14, c6_h_y, 14,
                  sf_mex_call(c6_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (c6_sp, NULL, "message", 1U, 1U, 14, c6_j_y)));
    }

    c6_b2 = (c6_nc + 1 < 1);
    if (c6_b2) {
      c6_i2 = 0;
    } else {
      c6_i2 = c6_nc + 1;
    }

    c6_c_size[0] = c6_i2;
  }
}

static boolean_T c6_issorted(SFc6_untitledInstanceStruct *chartInstance, int32_T
  c6_x_data[], int32_T c6_x_size[1])
{
  real_T c6_d;
  real_T c6_d1;
  int32_T c6_subs[2];
  int32_T c6_a;
  int32_T c6_b;
  int32_T c6_b_a;
  int32_T c6_b_b;
  int32_T c6_b_dim;
  int32_T c6_b_k;
  int32_T c6_b_n;
  int32_T c6_c_dim;
  int32_T c6_c_k;
  int32_T c6_d_dim;
  int32_T c6_dim;
  int32_T c6_i;
  int32_T c6_i1;
  int32_T c6_k;
  int32_T c6_n;
  int32_T c6_nx;
  int32_T c6_varargin_1;
  int32_T c6_x1;
  int32_T c6_x2;
  boolean_T c6_c_b;
  boolean_T c6_exitg1;
  boolean_T c6_exitg2;
  boolean_T c6_y;
  (void)chartInstance;
  c6_y = true;
  c6_dim = 2;
  if (c6_x_size[0] != 1) {
    c6_dim = 1;
  }

  if (c6_dim <= 1) {
    c6_d = (real_T)c6_x_size[0];
  } else {
    c6_d = 1.0;
  }

  c6_nx = (int32_T)c6_d;
  if ((c6_x_size[0] == 0) || (c6_nx == 1)) {
  } else {
    c6_b_dim = c6_dim;
    c6_y = true;
    if (c6_b_dim == 2) {
      c6_n = 0;
    } else {
      c6_n = 1;
    }

    c6_i = (uint8_T)c6_n - 1;
    c6_k = 0;
    c6_exitg1 = false;
    while ((!c6_exitg1) && (c6_k <= c6_i)) {
      c6_c_dim = c6_b_dim;
      c6_y = true;
      if (c6_c_dim == 1) {
        c6_d1 = (real_T)c6_x_size[0];
        c6_b_n = (int32_T)c6_d1 - 1;
      } else {
        c6_b_n = c6_x_size[0];
      }

      c6_i1 = (uint16_T)c6_b_n - 1;
      c6_b_k = 1;
      c6_exitg2 = false;
      while ((!c6_exitg2) && (c6_b_k - 1 <= c6_i1)) {
        c6_c_k = c6_b_k;
        c6_d_dim = c6_c_dim - 1;
        c6_varargin_1 = c6_c_k;
        c6_x1 = c6_x_data[c6_varargin_1 - 1];
        c6_subs[0] = c6_varargin_1;
        c6_subs[1] = 1;
        c6_subs[c6_d_dim]++;
        c6_x2 = c6_x_data[c6_subs[0] - 1];
        c6_subs[0] = c6_x1;
        c6_subs[1] = c6_x2;
        c6_a = c6_subs[0];
        c6_b = c6_subs[1];
        c6_b_a = c6_a;
        c6_b_b = c6_b;
        c6_c_b = (c6_b_a <= c6_b_b);
        c6_y = c6_c_b;
        if (!c6_y) {
          c6_exitg2 = true;
        } else {
          c6_b_k++;
        }
      }

      if (!c6_y) {
        c6_exitg1 = true;
      } else {
        c6_k++;
      }
    }
  }

  return c6_y;
}

static void c6_b_introsort(SFc6_untitledInstanceStruct *chartInstance, const
  emlrtStack *c6_sp, int32_T c6_x_data[], int32_T c6_x_size[1], int32_T c6_xend,
  int32_T c6_b_x_data[], int32_T c6_b_x_size[1])
{
  int32_T c6_i;
  int32_T c6_loop_ub;
  c6_b_x_size[0] = c6_x_size[0];
  c6_loop_ub = c6_x_size[0] - 1;
  for (c6_i = 0; c6_i <= c6_loop_ub; c6_i++) {
    c6_b_x_data[c6_i] = c6_x_data[c6_i];
  }

  c6_d_introsort(chartInstance, c6_sp, c6_b_x_data, c6_xend);
}

static void c6_b_insertionsort(SFc6_untitledInstanceStruct *chartInstance,
  int32_T c6_x_data[], int32_T c6_x_size[1], int32_T c6_xend, int32_T
  c6_b_x_data[], int32_T c6_b_x_size[1])
{
  int32_T c6_i;
  int32_T c6_loop_ub;
  c6_b_x_size[0] = c6_x_size[0];
  c6_loop_ub = c6_x_size[0] - 1;
  for (c6_i = 0; c6_i <= c6_loop_ub; c6_i++) {
    c6_b_x_data[c6_i] = c6_x_data[c6_i];
  }

  c6_e_insertionsort(chartInstance, c6_b_x_data, c6_xend);
}

static void c6_c_insertionsort(SFc6_untitledInstanceStruct *chartInstance, const
  emlrtStack *c6_sp, int32_T c6_x_data[], int32_T c6_x_size[1], int32_T
  c6_xstart, int32_T c6_xend, int32_T c6_b_x_data[], int32_T c6_b_x_size[1])
{
  int32_T c6_i;
  int32_T c6_loop_ub;
  c6_b_x_size[0] = c6_x_size[0];
  c6_loop_ub = c6_x_size[0] - 1;
  for (c6_i = 0; c6_i <= c6_loop_ub; c6_i++) {
    c6_b_x_data[c6_i] = c6_x_data[c6_i];
  }

  c6_f_insertionsort(chartInstance, c6_sp, c6_b_x_data, c6_xstart, c6_xend);
}

static void c6_heapsort(SFc6_untitledInstanceStruct *chartInstance, int32_T
  c6_x_data[], int32_T c6_x_size[1], int32_T c6_xstart, int32_T c6_xend, int32_T
  c6_b_x_data[], int32_T c6_b_x_size[1])
{
  int32_T c6_i;
  int32_T c6_loop_ub;
  c6_b_x_size[0] = c6_x_size[0];
  c6_loop_ub = c6_x_size[0] - 1;
  for (c6_i = 0; c6_i <= c6_loop_ub; c6_i++) {
    c6_b_x_data[c6_i] = c6_x_data[c6_i];
  }

  c6_b_heapsort(chartInstance, c6_b_x_data, c6_xstart, c6_xend);
}

static void c6_heapify(SFc6_untitledInstanceStruct *chartInstance, int32_T
  c6_x_data[], int32_T c6_x_size[1], int32_T c6_idx, int32_T c6_xstart, int32_T
  c6_xend, int32_T c6_b_x_data[], int32_T c6_b_x_size[1])
{
  int32_T c6_i;
  int32_T c6_loop_ub;
  c6_b_x_size[0] = c6_x_size[0];
  c6_loop_ub = c6_x_size[0] - 1;
  for (c6_i = 0; c6_i <= c6_loop_ub; c6_i++) {
    c6_b_x_data[c6_i] = c6_x_data[c6_i];
  }

  c6_b_heapify(chartInstance, c6_b_x_data, c6_idx, c6_xstart, c6_xend);
}

static void c6_indexShapeCheck(SFc6_untitledInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c6_b_indexShapeCheck(SFc6_untitledInstanceStruct *chartInstance,
  const emlrtStack *c6_sp, int32_T c6_matrixSize, int32_T c6_indexSize[2])
{
  static char_T c6_cv[30] = { 'C', 'o', 'd', 'e', 'r', ':', 'F', 'E', ':', 'P',
    'o', 't', 'e', 'n', 't', 'i', 'a', 'l', 'V', 'e', 'c', 't', 'o', 'r', 'V',
    'e', 'c', 't', 'o', 'r' };

  emlrtStack c6_st;
  const mxArray *c6_b_y = NULL;
  const mxArray *c6_y = NULL;
  int32_T c6_size1;
  boolean_T c6_b;
  boolean_T c6_b_b;
  boolean_T c6_b_c;
  boolean_T c6_c;
  boolean_T c6_nonSingletonDimFound;
  (void)chartInstance;
  c6_st.prev = c6_sp;
  c6_st.tls = c6_sp->tls;
  c6_size1 = c6_matrixSize;
  if (c6_size1 != 1) {
    c6_b = false;
  } else {
    c6_b = true;
  }

  if (c6_b) {
    c6_nonSingletonDimFound = false;
    if (c6_indexSize[1] != 1) {
      c6_nonSingletonDimFound = true;
    }

    c6_b_b = c6_nonSingletonDimFound;
    if (c6_b_b) {
      c6_c = true;
    } else {
      c6_c = false;
    }
  } else {
    c6_c = false;
  }

  c6_st.site = &c6_ub_emlrtRSI;
  c6_b_c = c6_c;
  if (c6_b_c) {
    c6_y = NULL;
    sf_mex_assign(&c6_y, sf_mex_create("y", c6_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    c6_b_y = NULL;
    sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_cv, 10, 0U, 1, 0U, 2, 1, 30),
                  false);
    sf_mex_call(&c6_st, &c6_n_emlrtMCI, "error", 0U, 2U, 14, c6_y, 14,
                sf_mex_call(&c6_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (&c6_st, NULL, "message", 1U, 1U, 14, c6_b_y)));
  }
}

static real_T c6_c_sumColumnB(SFc6_untitledInstanceStruct *chartInstance, real_T
  c6_x_data[], int32_T c6_vlen)
{
  real_T c6_b_y;
  real_T c6_c_y;
  real_T c6_y;
  int32_T c6_a;
  int32_T c6_b_k;
  int32_T c6_b_vlen;
  int32_T c6_c_k;
  int32_T c6_c_vlen;
  int32_T c6_d_k;
  int32_T c6_e_k;
  int32_T c6_f_k;
  int32_T c6_g_k;
  int32_T c6_h_k;
  int32_T c6_i;
  int32_T c6_i1;
  int32_T c6_i2;
  int32_T c6_i_k;
  int32_T c6_inb;
  int32_T c6_k;
  int32_T c6_lidx;
  int32_T c6_nfb;
  int32_T c6_nleft;
  int32_T c6_vstart;
  (void)chartInstance;
  if (c6_vlen <= 1024) {
    c6_b_vlen = c6_vlen - 1;
    c6_y = c6_x_data[0];
    c6_i = c6_b_vlen;
    c6_i1 = (uint16_T)c6_i;
    for (c6_b_k = 0; c6_b_k < c6_i1; c6_b_k++) {
      c6_e_k = c6_b_k;
      c6_y += c6_x_data[c6_e_k + 1];
    }
  } else {
    c6_a = c6_vlen;
    c6_nfb = (uint16_T)((uint32_T)(uint16_T)c6_a >> 10);
    c6_inb = c6_nfb << 10;
    c6_y = c6_x_data[0];
    for (c6_k = 0; c6_k < 1023; c6_k++) {
      c6_d_k = c6_k;
      c6_y += c6_x_data[c6_d_k + 1];
    }

    for (c6_c_k = 2; c6_c_k <= c6_nfb; c6_c_k++) {
      c6_b_y = c6_x_data[1024];
      for (c6_f_k = 0; c6_f_k < 1023; c6_f_k++) {
        c6_g_k = c6_f_k;
        c6_b_y += c6_x_data[c6_g_k + 1025];
      }

      c6_y += c6_b_y;
    }

    if (c6_vlen > c6_inb) {
      c6_nleft = c6_vlen - c6_inb;
      c6_lidx = c6_inb;
      c6_c_vlen = c6_nleft - 1;
      c6_vstart = c6_lidx;
      c6_c_y = c6_x_data[c6_vstart];
      c6_i2 = c6_c_vlen;
      for (c6_h_k = 0; c6_h_k < c6_i2; c6_h_k++) {
        c6_i_k = c6_h_k;
        c6_c_y += c6_x_data[(c6_vstart + c6_i_k) + 1];
      }

      c6_y += c6_c_y;
    }
  }

  return c6_y;
}

const mxArray *sf_c6_untitled_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1, 0U, 2, 0, 1), false);
  return c6_nameCaptureInfo;
}

static real_T c6_emlrt_marshallIn(SFc6_untitledInstanceStruct *chartInstance,
  const mxArray *c6_nullptr, const char_T *c6_identifier)
{
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  c6_thisId.fIdentifier = (const char_T *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nullptr), &c6_thisId);
  sf_mex_destroy(&c6_nullptr);
  return c6_y;
}

static real_T c6_b_emlrt_marshallIn(SFc6_untitledInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_d;
  real_T c6_y;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_c_emlrt_marshallIn(SFc6_untitledInstanceStruct *chartInstance,
  const mxArray *c6_nullptr, const char_T *c6_identifier, real_T c6_y[2500])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = (const char_T *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nullptr), &c6_thisId, c6_y);
  sf_mex_destroy(&c6_nullptr);
}

static void c6_d_emlrt_marshallIn(SFc6_untitledInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, real_T c6_y[2500])
{
  real_T c6_dv[2500];
  int32_T c6_i;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), c6_dv, 1, 0, 0U, 1, 0U, 2, 2500,
                1);
  for (c6_i = 0; c6_i < 2500; c6_i++) {
    c6_y[c6_i] = c6_dv[c6_i];
  }

  sf_mex_destroy(&c6_u);
}

static real_T c6_e_emlrt_marshallIn(SFc6_untitledInstanceStruct *chartInstance,
  const mxArray *c6_nullptr, const char_T *c6_identifier, boolean_T *c6_svPtr)
{
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  c6_thisId.fIdentifier = (const char_T *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_y = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nullptr), &c6_thisId,
    c6_svPtr);
  sf_mex_destroy(&c6_nullptr);
  return c6_y;
}

static real_T c6_f_emlrt_marshallIn(SFc6_untitledInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId, boolean_T
  *c6_svPtr)
{
  real_T c6_d;
  real_T c6_y;
  (void)chartInstance;
  if (mxIsEmpty(c6_u)) {
    *c6_svPtr = false;
  } else {
    *c6_svPtr = true;
    sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d, 1, 0, 0U, 0, 0U, 0);
    c6_y = c6_d;
  }

  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_slStringInitializeDynamicBuffers(SFc6_untitledInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c6_feval(SFc6_untitledInstanceStruct *chartInstance, const
  emlrtStack *c6_sp, const mxArray *c6_input0, const mxArray *c6_input1)
{
  const mxArray *c6_m = NULL;
  (void)chartInstance;
  c6_m = NULL;
  sf_mex_assign(&c6_m, sf_mex_call(c6_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c6_input0), 14, sf_mex_dup(c6_input1)), false);
  sf_mex_destroy(&c6_input0);
  sf_mex_destroy(&c6_input1);
  return c6_m;
}

static void c6_b_feval(SFc6_untitledInstanceStruct *chartInstance, const
  emlrtStack *c6_sp, const mxArray *c6_input0, const mxArray *c6_input1)
{
  (void)chartInstance;
  sf_mex_call(c6_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c6_input0), 14,
              sf_mex_dup(c6_input1));
  sf_mex_destroy(&c6_input0);
  sf_mex_destroy(&c6_input1);
}

static void c6_c_introsort(SFc6_untitledInstanceStruct *chartInstance, int32_T
  c6_b_x[10], c6_anonymous_function *c6_cmp)
{
  c6_anonymous_function c6_b_cmp;
  c6_b_cmp = *c6_cmp;
  c6_d_insertionsort(chartInstance, c6_b_x, &c6_b_cmp);
}

static void c6_d_insertionsort(SFc6_untitledInstanceStruct *chartInstance,
  int32_T c6_b_x[10], c6_anonymous_function *c6_cmp)
{
  c6_cell_16 c6_workspace;
  int32_T c6_a[10];
  int32_T c6_b[10];
  int32_T c6_ai;
  int32_T c6_aj;
  int32_T c6_b_i;
  int32_T c6_b_j;
  int32_T c6_c_i;
  int32_T c6_i;
  int32_T c6_i1;
  int32_T c6_i2;
  int32_T c6_i3;
  int32_T c6_idx;
  int32_T c6_j;
  int32_T c6_k;
  int32_T c6_varargin_1;
  int32_T c6_varargin_2;
  int32_T c6_xc;
  boolean_T c6_exitg1;
  boolean_T c6_varargout_1;
  (void)chartInstance;
  for (c6_k = 0; c6_k < 9; c6_k++) {
    c6_xc = c6_b_x[c6_k + 1];
    c6_idx = c6_k;
    c6_exitg1 = false;
    while ((!c6_exitg1) && (c6_idx + 1 >= 1)) {
      c6_varargin_1 = c6_xc;
      c6_varargin_2 = c6_b_x[c6_idx];
      for (c6_i = 0; c6_i < 10; c6_i++) {
        c6_workspace.f1[c6_i] = c6_cmp->workspace.a[c6_i];
      }

      for (c6_i1 = 0; c6_i1 < 10; c6_i1++) {
        c6_workspace.f2[c6_i1] = c6_cmp->workspace.b[c6_i1];
      }

      for (c6_i2 = 0; c6_i2 < 10; c6_i2++) {
        c6_a[c6_i2] = c6_workspace.f1[c6_i2];
      }

      for (c6_i3 = 0; c6_i3 < 10; c6_i3++) {
        c6_b[c6_i3] = c6_workspace.f2[c6_i3];
      }

      c6_b_i = c6_varargin_1;
      c6_j = c6_varargin_2;
      c6_c_i = c6_b_i - 1;
      c6_b_j = c6_j - 1;
      c6_ai = c6_a[c6_c_i];
      c6_aj = c6_a[c6_b_j];
      if (c6_ai < c6_aj) {
        c6_varargout_1 = true;
      } else if (c6_ai == c6_aj) {
        c6_varargout_1 = (c6_b[c6_c_i] < c6_b[c6_b_j]);
      } else {
        c6_varargout_1 = false;
      }

      if (c6_varargout_1) {
        c6_b_x[c6_idx + 1] = c6_b_x[c6_idx];
        c6_idx--;
      } else {
        c6_exitg1 = true;
      }
    }

    c6_b_x[c6_idx + 1] = c6_xc;
  }
}

static void c6_d_introsort(SFc6_untitledInstanceStruct *chartInstance, const
  emlrtStack *c6_sp, int32_T c6_x_data[], int32_T c6_xend)
{
  static char_T c6_cv[28] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'S', 't', 'a', 'c', 'k', 'P', 'u', 's', 'h', 'L', 'i',
    'm', 'i', 't' };

  static char_T c6_cv2[28] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'S', 't', 'a', 'c', 'k', 'P', 'u', 's', 'h', 'L', 'i',
    'm', 'i', 't' };

  static char_T c6_cv3[28] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'S', 't', 'a', 'c', 'k', 'P', 'u', 's', 'h', 'L', 'i',
    'm', 'i', 't' };

  static char_T c6_cv1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'S', 't', 'a', 'c', 'k', 'P', 'o', 'p', 'E', 'm', 'p',
    't', 'y' };

  c6_coder_internal_stack c6_b_st;
  c6_sBaHy6MF1FZJsDHxMqvBaiH c6_c_x;
  c6_sBaHy6MF1FZJsDHxMqvBaiH c6_d_x;
  c6_sBaHy6MF1FZJsDHxMqvBaiH c6_frame;
  emlrtStack c6_st;
  const mxArray *c6_b_y = NULL;
  const mxArray *c6_c_y = NULL;
  const mxArray *c6_d_y = NULL;
  const mxArray *c6_e_y = NULL;
  const mxArray *c6_f_y = NULL;
  const mxArray *c6_g_y = NULL;
  const mxArray *c6_h_y = NULL;
  const mxArray *c6_i_y = NULL;
  real_T c6_d;
  real_T c6_d1;
  int32_T c6_iv[2];
  int32_T c6_MAXDEPTH;
  int32_T c6_a;
  int32_T c6_b;
  int32_T c6_b_b;
  int32_T c6_b_n;
  int32_T c6_b_nd;
  int32_T c6_b_p;
  int32_T c6_b_x;
  int32_T c6_b_xend;
  int32_T c6_b_xstart;
  int32_T c6_c;
  int32_T c6_c_n;
  int32_T c6_c_nd;
  int32_T c6_d_n;
  int32_T c6_depth;
  int32_T c6_e_n;
  int32_T c6_exitg2;
  int32_T c6_exitg3;
  int32_T c6_i;
  int32_T c6_j;
  int32_T c6_n;
  int32_T c6_nd;
  int32_T c6_p;
  int32_T c6_pivot;
  int32_T c6_pmax;
  int32_T c6_pmin;
  int32_T c6_pow2p;
  int32_T c6_t;
  int32_T c6_xmid;
  int32_T c6_xstart;
  int32_T c6_y;
  boolean_T c6_exitg1;
  c6_st.prev = c6_sp;
  c6_st.tls = c6_sp->tls;
  if (c6_xend <= 1) {
  } else if (c6_xend <= 32) {
    c6_e_insertionsort(chartInstance, c6_x_data, c6_xend);
  } else {
    c6_n = c6_xend;
    c6_b_x = c6_n;
    c6_p = c6_b_x;
    c6_b_n = c6_p;
    c6_c_n = c6_b_n;
    c6_pmax = 31;
    c6_pmin = 0;
    c6_exitg1 = false;
    while ((!c6_exitg1) && (c6_pmax - c6_pmin > 1)) {
      c6_p = (c6_pmin + c6_pmax) >> 1;
      c6_pow2p = 1 << c6_p;
      if (c6_pow2p == c6_c_n) {
        c6_pmax = c6_p;
        c6_exitg1 = true;
      } else if (c6_pow2p > c6_c_n) {
        c6_pmax = c6_p;
      } else {
        c6_pmin = c6_p;
      }
    }

    c6_p = c6_pmax - 1;
    c6_b = c6_p;
    c6_MAXDEPTH = c6_b << 1;
    c6_frame.xstart = 1;
    c6_frame.xend = c6_xend;
    c6_frame.depth = 0;
    c6_b_b = c6_MAXDEPTH;
    c6_y = c6_b_b << 1;
    c6_st.site = &c6_rb_emlrtRSI;
    c6_d_n = c6_y;
    c6_d = (real_T)c6_d_n;
    if (!(c6_d >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c6_d, &c6_emlrtDCI, &c6_st);
    }

    c6_iv[0] = (int32_T)muDoubleScalarFloor(c6_d);
    c6_d1 = 1.0;
    if (!(c6_d1 >= 0.0)) {
      emlrtNonNegativeCheckR2012b(c6_d1, &c6_emlrtDCI, &c6_st);
    }

    c6_b_st.d.size[0] = c6_iv[0];
    c6_st.site = &c6_mb_emlrtRSI;
    c6_nd = c6_b_st.d.size[0];
    if (c6_nd <= 0) {
      c6_b_y = NULL;
      sf_mex_assign(&c6_b_y, sf_mex_create("y", c6_cv, 10, 0U, 1, 0U, 2, 1, 28),
                    false);
      c6_c_y = NULL;
      sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_cv, 10, 0U, 1, 0U, 2, 1, 28),
                    false);
      sf_mex_call(&c6_st, &c6_l_emlrtMCI, "error", 0U, 2U, 14, c6_b_y, 14,
                  sf_mex_call(&c6_st, NULL, "getString", 1U, 1U, 14, sf_mex_call
        (&c6_st, NULL, "message", 1U, 1U, 14, c6_c_y)));
    }

    c6_b_st.d.data[0] = c6_frame;
    c6_b_st.n = 1;
    do {
      c6_exitg2 = 0;
      c6_e_n = c6_b_st.n;
      if (c6_e_n > 0) {
        c6_st.site = &c6_nb_emlrtRSI;
        if (c6_b_st.n <= 0) {
          c6_d_y = NULL;
          sf_mex_assign(&c6_d_y, sf_mex_create("y", c6_cv1, 10, 0U, 1, 0U, 2, 1,
            27), false);
          c6_e_y = NULL;
          sf_mex_assign(&c6_e_y, sf_mex_create("y", c6_cv1, 10, 0U, 1, 0U, 2, 1,
            27), false);
          sf_mex_call(&c6_st, &c6_m_emlrtMCI, "error", 0U, 2U, 14, c6_d_y, 14,
                      sf_mex_call(&c6_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c6_st, NULL, "message", 1U, 1U, 14, c6_e_y)));
        }

        c6_frame = c6_b_st.d.data[c6_b_st.n - 1];
        c6_b_st.n--;
        c6_xstart = c6_frame.xstart;
        c6_xend = c6_frame.xend;
        c6_depth = c6_frame.depth + 1;
        if ((c6_xend - c6_xstart) + 1 <= 32) {
          c6_st.site = &c6_ob_emlrtRSI;
          c6_f_insertionsort(chartInstance, &c6_st, c6_x_data, c6_xstart,
                             c6_xend);
        } else if (c6_depth - 1 == c6_MAXDEPTH) {
          c6_b_heapsort(chartInstance, c6_x_data, c6_xstart, c6_xend);
        } else {
          c6_b_xstart = c6_xstart - 1;
          c6_b_xend = c6_xend - 1;
          c6_a = c6_b_xend - c6_b_xstart;
          c6_c = c6_div_nzp_s32(chartInstance, c6_a, 2, 0, 0U, 0, 0);
          c6_xmid = c6_b_xstart + c6_c;
          if (c6_x_data[c6_xmid] < c6_x_data[c6_b_xstart]) {
            c6_t = c6_x_data[c6_b_xstart];
            c6_x_data[c6_b_xstart] = c6_x_data[c6_xmid];
            c6_x_data[c6_xmid] = c6_t;
          }

          if (c6_x_data[c6_b_xend] < c6_x_data[c6_b_xstart]) {
            c6_t = c6_x_data[c6_b_xstart];
            c6_x_data[c6_b_xstart] = c6_x_data[c6_b_xend];
            c6_x_data[c6_b_xend] = c6_t;
          }

          if (c6_x_data[c6_b_xend] < c6_x_data[c6_xmid]) {
            c6_t = c6_x_data[c6_xmid];
            c6_x_data[c6_xmid] = c6_x_data[c6_b_xend];
            c6_x_data[c6_b_xend] = c6_t;
          }

          c6_pivot = c6_x_data[c6_xmid];
          c6_x_data[c6_xmid] = c6_x_data[c6_b_xend - 1];
          c6_x_data[c6_b_xend - 1] = c6_pivot;
          c6_i = c6_b_xstart;
          c6_j = c6_b_xend - 1;
          do {
            c6_exitg3 = 0;
            for (c6_i++; c6_x_data[c6_i] < c6_pivot; c6_i++) {
            }

            for (c6_j--; c6_pivot < c6_x_data[c6_j]; c6_j--) {
            }

            if (c6_i + 1 >= c6_j + 1) {
              c6_exitg3 = 1;
            } else {
              c6_t = c6_x_data[c6_i];
              c6_x_data[c6_i] = c6_x_data[c6_j];
              c6_x_data[c6_j] = c6_t;
            }
          } while (c6_exitg3 == 0);

          c6_b_p = c6_i + 1;
          c6_x_data[c6_b_xend - 1] = c6_x_data[c6_i];
          c6_x_data[c6_i] = c6_pivot;
          if (c6_b_p + 1 < c6_xend) {
            c6_c_x.xstart = c6_b_p + 1;
            c6_c_x.xend = c6_xend;
            c6_c_x.depth = c6_depth;
            c6_st.site = &c6_pb_emlrtRSI;
            c6_b_nd = c6_b_st.d.size[0];
            if (c6_b_st.n >= c6_b_nd) {
              c6_f_y = NULL;
              sf_mex_assign(&c6_f_y, sf_mex_create("y", c6_cv2, 10, 0U, 1, 0U, 2,
                1, 28), false);
              c6_h_y = NULL;
              sf_mex_assign(&c6_h_y, sf_mex_create("y", c6_cv2, 10, 0U, 1, 0U, 2,
                1, 28), false);
              sf_mex_call(&c6_st, &c6_l_emlrtMCI, "error", 0U, 2U, 14, c6_f_y,
                          14, sf_mex_call(&c6_st, NULL, "getString", 1U, 1U, 14,
                sf_mex_call(&c6_st, NULL, "message", 1U, 1U, 14, c6_h_y)));
            }

            c6_b_st.d.data[c6_b_st.n] = c6_c_x;
            c6_b_st.n++;
          }

          if (c6_xstart < c6_b_p) {
            c6_d_x.xstart = c6_xstart;
            c6_d_x.xend = c6_b_p;
            c6_d_x.depth = c6_depth;
            c6_st.site = &c6_qb_emlrtRSI;
            c6_c_nd = c6_b_st.d.size[0];
            if (c6_b_st.n >= c6_c_nd) {
              c6_g_y = NULL;
              sf_mex_assign(&c6_g_y, sf_mex_create("y", c6_cv3, 10, 0U, 1, 0U, 2,
                1, 28), false);
              c6_i_y = NULL;
              sf_mex_assign(&c6_i_y, sf_mex_create("y", c6_cv3, 10, 0U, 1, 0U, 2,
                1, 28), false);
              sf_mex_call(&c6_st, &c6_l_emlrtMCI, "error", 0U, 2U, 14, c6_g_y,
                          14, sf_mex_call(&c6_st, NULL, "getString", 1U, 1U, 14,
                sf_mex_call(&c6_st, NULL, "message", 1U, 1U, 14, c6_i_y)));
            }

            c6_b_st.d.data[c6_b_st.n] = c6_d_x;
            c6_b_st.n++;
          }
        }
      } else {
        c6_exitg2 = 1;
      }
    } while (c6_exitg2 == 0);
  }
}

static void c6_e_insertionsort(SFc6_untitledInstanceStruct *chartInstance,
  int32_T c6_x_data[], int32_T c6_xend)
{
  int32_T c6_idx;
  int32_T c6_k;
  int32_T c6_xc;
  (void)chartInstance;
  for (c6_k = 2; c6_k <= c6_xend; c6_k++) {
    c6_xc = c6_x_data[c6_k - 1];
    c6_idx = c6_k - 1;
    while ((c6_idx >= 1) && (c6_xc < c6_x_data[c6_idx - 1])) {
      c6_x_data[c6_idx] = c6_x_data[c6_idx - 1];
      c6_idx--;
    }

    c6_x_data[c6_idx] = c6_xc;
  }
}

static void c6_f_insertionsort(SFc6_untitledInstanceStruct *chartInstance, const
  emlrtStack *c6_sp, int32_T c6_x_data[], int32_T c6_xstart, int32_T c6_xend)
{
  emlrtStack c6_b_st;
  emlrtStack c6_st;
  int32_T c6_a;
  int32_T c6_b;
  int32_T c6_b_a;
  int32_T c6_b_b;
  int32_T c6_i;
  int32_T c6_idx;
  int32_T c6_k;
  int32_T c6_xc;
  boolean_T c6_overflow;
  c6_st.prev = c6_sp;
  c6_st.tls = c6_sp->tls;
  c6_b_st.prev = &c6_st;
  c6_b_st.tls = c6_st.tls;
  c6_i = c6_xstart + 1;
  c6_st.site = &c6_sb_emlrtRSI;
  c6_a = c6_i;
  c6_b = c6_xend;
  c6_b_a = c6_a;
  c6_b_b = c6_b;
  if (c6_b_a > c6_b_b) {
    c6_overflow = false;
  } else {
    c6_overflow = (c6_b_b > 2147483646);
  }

  if (c6_overflow) {
    c6_b_st.site = &c6_tb_emlrtRSI;
    c6_check_forloop_overflow_error(chartInstance, &c6_b_st);
  }

  for (c6_k = c6_i; c6_k <= c6_xend; c6_k++) {
    c6_xc = c6_x_data[c6_k - 1];
    c6_idx = c6_k - 1;
    while ((c6_idx >= c6_xstart) && (c6_xc < c6_x_data[c6_idx - 1])) {
      c6_x_data[c6_idx] = c6_x_data[c6_idx - 1];
      c6_idx--;
    }

    c6_x_data[c6_idx] = c6_xc;
  }
}

static void c6_b_heapsort(SFc6_untitledInstanceStruct *chartInstance, int32_T
  c6_x_data[], int32_T c6_xstart, int32_T c6_xend)
{
  int32_T c6_b_n;
  int32_T c6_b_xend;
  int32_T c6_b_xstart;
  int32_T c6_i;
  int32_T c6_idx;
  int32_T c6_k;
  int32_T c6_n;
  int32_T c6_t;
  c6_n = c6_xend - c6_xstart;
  c6_b_xstart = c6_xstart;
  c6_b_xend = c6_xend;
  c6_b_n = c6_n + 1;
  for (c6_idx = c6_b_n; c6_idx >= 1; c6_idx--) {
    c6_b_heapify(chartInstance, c6_x_data, c6_idx, c6_b_xstart, c6_b_xend);
  }

  c6_i = c6_n;
  for (c6_k = 0; c6_k < c6_i; c6_k++) {
    c6_t = c6_x_data[c6_xend - 1];
    c6_x_data[c6_xend - 1] = c6_x_data[c6_xstart - 1];
    c6_x_data[c6_xstart - 1] = c6_t;
    c6_xend--;
    c6_b_heapify(chartInstance, c6_x_data, 1, c6_xstart, c6_xend);
  }
}

static void c6_b_heapify(SFc6_untitledInstanceStruct *chartInstance, int32_T
  c6_x_data[], int32_T c6_idx, int32_T c6_xstart, int32_T c6_xend)
{
  int32_T c6_b;
  int32_T c6_b_b;
  int32_T c6_b_y;
  int32_T c6_cmpIdx;
  int32_T c6_extremum;
  int32_T c6_extremumIdx;
  int32_T c6_leftIdx;
  int32_T c6_rightIdx;
  int32_T c6_xcmp;
  int32_T c6_xoff;
  int32_T c6_xr;
  int32_T c6_y;
  boolean_T c6_changed;
  (void)chartInstance;
  c6_changed = true;
  c6_xoff = c6_xstart - 1;
  c6_extremumIdx = (c6_idx + c6_xoff) - 1;
  c6_b = c6_idx;
  c6_y = c6_b << 1;
  c6_leftIdx = c6_y + c6_xoff;
  while (c6_changed && (c6_leftIdx < c6_xend)) {
    c6_changed = false;
    c6_rightIdx = c6_leftIdx;
    c6_extremum = c6_x_data[c6_extremumIdx];
    c6_cmpIdx = c6_leftIdx;
    c6_xcmp = c6_x_data[c6_leftIdx - 1];
    c6_xr = c6_x_data[c6_rightIdx];
    if (c6_xcmp < c6_xr) {
      c6_cmpIdx = c6_leftIdx + 1;
      c6_xcmp = c6_xr;
    }

    if (c6_extremum < c6_xcmp) {
      c6_x_data[c6_extremumIdx] = c6_xcmp;
      c6_x_data[c6_cmpIdx - 1] = c6_extremum;
      c6_extremumIdx = c6_cmpIdx - 1;
      c6_b_b = c6_cmpIdx - c6_xoff;
      c6_b_y = c6_b_b << 1;
      c6_leftIdx = c6_b_y + c6_xoff;
      c6_changed = true;
    }
  }

  if (c6_changed && (c6_leftIdx <= c6_xend)) {
    c6_extremum = c6_x_data[c6_extremumIdx];
    c6_xcmp = c6_x_data[c6_leftIdx - 1];
    if (c6_extremum < c6_xcmp) {
      c6_x_data[c6_extremumIdx] = c6_xcmp;
      c6_x_data[c6_leftIdx - 1] = c6_extremum;
    }
  }
}

static void c6_array_real_T_SetSize(SFc6_untitledInstanceStruct *chartInstance,
  const emlrtStack *c6_sp, c6_coder_array_real_T *c6_coderArray, const
  emlrtRTEInfo *c6_srcLocation, int32_T c6_size0)
{
  real_T *c6_newData;
  int32_T c6_newCapacity;
  int32_T c6_newNumel;
  (void)chartInstance;
  c6_coderArray->size[0] = c6_size0;
  c6_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c6_coderArray->size[0], c6_srcLocation, (void *)c6_sp);
  if (c6_newNumel > c6_coderArray->vector.allocated) {
    c6_newCapacity = c6_coderArray->vector.allocated;
    if (c6_newCapacity < 16) {
      c6_newCapacity = 16;
    }

    while (c6_newCapacity < c6_newNumel) {
      if (c6_newCapacity > 1073741823) {
        c6_newCapacity = MAX_int32_T;
      } else {
        c6_newCapacity <<= 1;
      }
    }

    c6_newData = (real_T *)emlrtMallocMex(sizeof(real_T) * (uint32_T)
      c6_newCapacity);
    if ((void *)c6_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c6_srcLocation, (void *)c6_sp);
    }

    if ((void *)c6_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c6_srcLocation, (void *)c6_sp);
    }

    if (c6_coderArray->vector.data != NULL) {
      memcpy(c6_newData, c6_coderArray->vector.data, sizeof(real_T) * (uint32_T)
             c6_coderArray->vector.numel);
      if (c6_coderArray->vector.owner) {
        emlrtFreeMex(c6_coderArray->vector.data);
      }
    }

    c6_coderArray->vector.data = c6_newData;
    c6_coderArray->vector.allocated = c6_newCapacity;
    c6_coderArray->vector.owner = true;
  }

  c6_coderArray->vector.numel = c6_newNumel;
}

static void c6_array_int32_T_SetSize(SFc6_untitledInstanceStruct *chartInstance,
  const emlrtStack *c6_sp, c6_coder_array_int32_T *c6_coderArray, const
  emlrtRTEInfo *c6_srcLocation, int32_T c6_size0)
{
  int32_T c6_newCapacity;
  int32_T c6_newNumel;
  int32_T *c6_newData;
  (void)chartInstance;
  c6_coderArray->size[0] = c6_size0;
  c6_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c6_coderArray->size[0], c6_srcLocation, (void *)c6_sp);
  if (c6_newNumel > c6_coderArray->vector.allocated) {
    c6_newCapacity = c6_coderArray->vector.allocated;
    if (c6_newCapacity < 16) {
      c6_newCapacity = 16;
    }

    while (c6_newCapacity < c6_newNumel) {
      if (c6_newCapacity > 1073741823) {
        c6_newCapacity = MAX_int32_T;
      } else {
        c6_newCapacity <<= 1;
      }
    }

    c6_newData = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
      c6_newCapacity);
    if ((void *)c6_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c6_srcLocation, (void *)c6_sp);
    }

    if ((void *)c6_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c6_srcLocation, (void *)c6_sp);
    }

    if (c6_coderArray->vector.data != NULL) {
      memcpy(c6_newData, c6_coderArray->vector.data, sizeof(int32_T) * (uint32_T)
             c6_coderArray->vector.numel);
      if (c6_coderArray->vector.owner) {
        emlrtFreeMex(c6_coderArray->vector.data);
      }
    }

    c6_coderArray->vector.data = c6_newData;
    c6_coderArray->vector.allocated = c6_newCapacity;
    c6_coderArray->vector.owner = true;
  }

  c6_coderArray->vector.numel = c6_newNumel;
}

static void c6_array_sparse_Constructor(SFc6_untitledInstanceStruct
  *chartInstance, c6_sparse *c6_pStruct)
{
  c6_array_real_T_Constructor(chartInstance, &c6_pStruct->d);
  c6_array_int32_T_Constructor(chartInstance, &c6_pStruct->colidx);
  c6_array_int32_T_Constructor(chartInstance, &c6_pStruct->rowidx);
}

static void c6_array_real_T_Constructor(SFc6_untitledInstanceStruct
  *chartInstance, c6_coder_array_real_T *c6_coderArray)
{
  (void)chartInstance;
  c6_coderArray->vector.data = (real_T *)NULL;
  c6_coderArray->vector.numel = 0;
  c6_coderArray->vector.allocated = 0;
  c6_coderArray->vector.owner = true;
  c6_coderArray->size[0] = 0;
}

static void c6_array_int32_T_Constructor(SFc6_untitledInstanceStruct
  *chartInstance, c6_coder_array_int32_T *c6_coderArray)
{
  (void)chartInstance;
  c6_coderArray->vector.data = (int32_T *)NULL;
  c6_coderArray->vector.numel = 0;
  c6_coderArray->vector.allocated = 0;
  c6_coderArray->vector.owner = true;
  c6_coderArray->size[0] = 0;
}

static void c6_array_real_T_Destructor(SFc6_untitledInstanceStruct
  *chartInstance, c6_coder_array_real_T *c6_coderArray)
{
  (void)chartInstance;
  if (c6_coderArray->vector.owner && (c6_coderArray->vector.data != (real_T *)
       NULL)) {
    emlrtFreeMex(c6_coderArray->vector.data);
  }
}

static void c6_array_sparse_Destructor(SFc6_untitledInstanceStruct
  *chartInstance, c6_sparse *c6_pStruct)
{
  c6_array_real_T_Destructor(chartInstance, &c6_pStruct->d);
  c6_array_int32_T_Destructor(chartInstance, &c6_pStruct->colidx);
  c6_array_int32_T_Destructor(chartInstance, &c6_pStruct->rowidx);
}

static void c6_array_int32_T_Destructor(SFc6_untitledInstanceStruct
  *chartInstance, c6_coder_array_int32_T *c6_coderArray)
{
  (void)chartInstance;
  if (c6_coderArray->vector.owner && (c6_coderArray->vector.data != (int32_T *)
       NULL)) {
    emlrtFreeMex(c6_coderArray->vector.data);
  }
}

static int32_T c6_div_nzp_s32(SFc6_untitledInstanceStruct *chartInstance,
  int32_T c6_numerator, int32_T c6_denominator, int32_T c6_EMLOvCount_src_loc,
  uint32_T c6_ssid_src_loc, int32_T c6_offset_src_loc, int32_T c6_length_src_loc)
{
  int32_T c6_quotient;
  uint32_T c6_absDenominator;
  uint32_T c6_absNumerator;
  uint32_T c6_tempAbsQuotient;
  boolean_T c6_quotientNeedsNegation;
  (void)chartInstance;
  (void)c6_EMLOvCount_src_loc;
  (void)c6_ssid_src_loc;
  (void)c6_offset_src_loc;
  (void)c6_length_src_loc;
  if (c6_numerator < 0) {
    c6_absNumerator = ~(uint32_T)c6_numerator + 1U;
  } else {
    c6_absNumerator = (uint32_T)c6_numerator;
  }

  if (c6_denominator < 0) {
    c6_absDenominator = ~(uint32_T)c6_denominator + 1U;
  } else {
    c6_absDenominator = (uint32_T)c6_denominator;
  }

  c6_quotientNeedsNegation = ((c6_numerator < 0) != (c6_denominator < 0));
  c6_tempAbsQuotient = c6_absNumerator / c6_absDenominator;
  if (c6_quotientNeedsNegation) {
    c6_quotient = -(int32_T)c6_tempAbsQuotient;
  } else {
    c6_quotient = (int32_T)c6_tempAbsQuotient;
  }

  return c6_quotient;
}

static int32_T c6__s32_add__(SFc6_untitledInstanceStruct *chartInstance, int32_T
  c6_b, int32_T c6_c, int32_T c6_EMLOvCount_src_loc, uint32_T c6_ssid_src_loc,
  int32_T c6_offset_src_loc, int32_T c6_length_src_loc)
{
  int32_T c6_a;
  (void)c6_EMLOvCount_src_loc;
  c6_a = c6_b + c6_c;
  if (((c6_a ^ c6_b) & (c6_a ^ c6_c)) < 0) {
    sf_data_overflow_error(chartInstance->S, c6_ssid_src_loc, c6_offset_src_loc,
      c6_length_src_loc);
  }

  return c6_a;
}

static int32_T c6__s32_minus__(SFc6_untitledInstanceStruct *chartInstance,
  int32_T c6_b, int32_T c6_c, int32_T c6_EMLOvCount_src_loc, uint32_T
  c6_ssid_src_loc, int32_T c6_offset_src_loc, int32_T c6_length_src_loc)
{
  int32_T c6_a;
  (void)c6_EMLOvCount_src_loc;
  c6_a = c6_b - c6_c;
  if (((c6_b ^ c6_a) & (c6_b ^ c6_c)) < 0) {
    sf_data_overflow_error(chartInstance->S, c6_ssid_src_loc, c6_offset_src_loc,
      c6_length_src_loc);
  }

  return c6_a;
}

static void init_dsm_address_info(SFc6_untitledInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc6_untitledInstanceStruct *chartInstance)
{
  chartInstance->c6_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c6_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c6_qrs_envelope = (real_T (*)[2500])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c6_ecg_in = (real_T (*)[2500])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c6_bpm = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c6_untitled_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3459180528U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3885230347U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1356374118U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2095569351U);
}

mxArray *sf_c6_untitled_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString("coder.internal.CXSparseAPI"));
  return(mxcell3p);
}

mxArray *sf_c6_untitled_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("makeCXSparseMatrix");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c6_untitled_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c6_untitled(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiBuYGZgYAPSHEDMxAABrFA+IxAzQ2mIOAtcXAGISyoLUkHixUXJnilAOi8xF8x"
    "PLK3wzEvLB5tvwYAwnw2L+YxI5nNCxSHggz1l+kUcQPoNkPSzEPCfAJCXVJALdjcsfAbO/YZg9z"
    "sQcD8Pivsh/MKi4vjUvLLUnHxI/FDHPwIOlOnHtB+bf9jR/APiA+MkviwxB6z/AgP+9MqIll6Zo"
    "HyQnhyGTIYCqDscCPiDCc0fAjBPKKQ5QBjpVAkPEAAAjg0fuw=="
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_untitled_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "s2uozG1AkCqci0m4ZR8f7rB";
}

static void sf_opaque_initialize_c6_untitled(void *chartInstanceVar)
{
  initialize_params_c6_untitled((SFc6_untitledInstanceStruct*) chartInstanceVar);
  initialize_c6_untitled((SFc6_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_untitled(void *chartInstanceVar)
{
  enable_c6_untitled((SFc6_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_untitled(void *chartInstanceVar)
{
  disable_c6_untitled((SFc6_untitledInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_untitled(void *chartInstanceVar)
{
  sf_gateway_c6_untitled((SFc6_untitledInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c6_untitled(SimStruct* S)
{
  return get_sim_state_c6_untitled((SFc6_untitledInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c6_untitled(SimStruct* S, const mxArray *st)
{
  set_sim_state_c6_untitled((SFc6_untitledInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c6_untitled(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_untitledInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_untitled_optimization_info();
    }

    mdl_cleanup_runtime_resources_c6_untitled((SFc6_untitledInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c6_untitled(void *chartInstanceVar)
{
  mdl_start_c6_untitled((SFc6_untitledInstanceStruct*) chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc6_untitledInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c6_untitled(void *chartInstanceVar)
{
  mdl_terminate_c6_untitled((SFc6_untitledInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_untitled(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_untitled((SFc6_untitledInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c6_untitled_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [22] = {
    "eNrdWM2P20QUn6RhS6FUQUJ8SEj0yLGlCHpAJbv5WCJ22ajJFqmqtJrYz8ko47F3PrKbnjgg/gP",
    "unLjwh3DlyJ/RGz3yxnGywWsSj7OoWyw5zrP9mzfvN+9rTCrdQ4LHHTx/+YiQHby+iWeVzI83Ur",
    "mycs7v18hXqdx7ixBvTKXuiiAi7ocX+TAC0TdBwM4dscKEPSppqEroFTSEx6AibjSLhNvkmQhAg",
    "vBwgDiS2kmvYqHhTEw6RnhWs/p+zLxxfxwZ7u/hgNQ/Enz2b3pjo3uoscUkeLoD4OuxjMxo3OF0",
    "tJ4Fqc+aY/AmyoTOXCnQfRNbU9Wh4ZrFHNrn4HWF0hRZUBvs7WuqoanPnT2Eqf4CHYUxZ1QU53p",
    "MVR9i9A4Nx7GPv0dGI3sF9aK+IRNUR5JR3g5503p4QWyP4zwP0a25M8861C0YmtGIiZFlV5oQBN",
    "qPflKAq6AZTUHSERwJxxi01rXPkwVe+mXxGOxatywVgyacr4oqhU30tqfIkCqpt+OJJuVcuWEHU",
    "XwAU+CJ/hbVtAR2rt8BrBTzB9ETKm0UOEaSEezUQIptRsJnxVd4mkElCfc7TJ4F4Cy0LgU+0ryc",
    "+nKgTT5plI7CJoZR6+CgoL7L2K7QIAPqQeHcJylTgBNO/MpRr88UHXKLRpZ0YmXhEUCUhhIVGNE",
    "6i+QEOXZNshdc2UhwQ4M/ghZoSBJGG737CeWm4JxDhRnOusexwozlphexNn5KgT3qjcG39YRxOA",
    "RlB1CF8zPWkV20dsr0rAXKkywuGklGgY+FxLI0mMVwLCYiOhMdGYX9tCNY41cAmDWoFFgW9rAsy",
    "VkHJ19s1hJOB9azyrRnIdWcDq1v7IPAymJttZWQehhVbYGtG05oG2yfPcfSLhRTGtupWTuJAT/p",
    "Rz+suPWj76byg2UsddVA4kpRLMMCO6XdYdLswYCFkNzoU+wp5mJ6WL33yIXeW9X1eqv4r1ISR7b",
    "ENVZwtRx+3l7B1VPZ++LECEwuluM8/bcL8FwERy7hLvhdXD9dwVdy9JKV6zbrssrTOxk9tQxuJ+",
    "Xqp/2ff332+4/s5fvP/qr/5r/Yyi9qbn58J5U/XvRly8o1vZTc7bvfbPCDDzJ+YGX1mYme79/fn",
    "TRPPXYv/Pzp44fBl3IvGe+HG+vneyMz38X9u3hqTGxJnpRe10/3WFamZt772/Efrsx3ZwMft1b8",
    "iZAXX2+Hf6+RXcfaBvvqKA3j8B9+++rmf79RJO5vZ9bbyqdSnYDArjOar8/V2FNvbIe/rD/Pnps",
    "Ze6yMa3Iyxbxu8X8Qt/iqprLFcMJInJMn8uyoZuyoL4y4GzTmf0ZXwsfrVoeuO+4qeSlSHyslcd",
    "X/sB5fJW5b+1zr/uv+/rp6QzLv16+xHevyk0v/d93s+tOxfnySyo+W32SaY8b9nF1h+hg3bkHe0",
    "/+Jf7905G/Rj7Ytf+lH5acPdgXlM9wGzrfZ6e2etN8zl48kUJW/134VdahIfOf1k/t735auY38D",
    "daEL6w==",
    ""
  };

  static char newstr [1509] = "";
  newstr[0] = '\0';
  for (i = 0; i < 22; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c6_untitled(SimStruct *S)
{
  const char* newstr = sf_c6_untitled_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(2794801030U));
  ssSetChecksum1(S,(1770309468U));
  ssSetChecksum2(S,(4150007544U));
  ssSetChecksum3(S,(4033129232U));
}

static void mdlRTW_c6_untitled(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c6_untitled(SimStruct *S)
{
  SFc6_untitledInstanceStruct *chartInstance;
  chartInstance = (SFc6_untitledInstanceStruct *)utMalloc(sizeof
    (SFc6_untitledInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc6_untitledInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  if (ssGetSampleTime(S, 0) == CONTINUOUS_SAMPLE_TIME && ssGetOffsetTime(S, 0) ==
      0 && sfHasContStates(S)> 0 &&
      !supportsLegacyBehaviorForPersistentVarInContinuousTime(S)) {
    sf_error_out_about_continuous_sample_time_with_persistent_vars(S);
  }

  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_untitled;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c6_untitled;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c6_untitled;
  chartInstance->chartInfo.mdlTerminate = sf_opaque_mdl_terminate_c6_untitled;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c6_untitled;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_untitled;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_untitled;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c6_untitled;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c6_untitled;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c6_untitled;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_untitled;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_untitled;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c6_untitled(chartInstance);
}

void c6_untitled_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c6_untitled(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_untitled(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_untitled(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_untitled_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
