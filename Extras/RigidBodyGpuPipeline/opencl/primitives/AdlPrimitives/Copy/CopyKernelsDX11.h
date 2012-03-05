static const char* copyKernelsDX11= \
"/*\n"
"		2011 Takahiro Harada\n"
"*/\n"
"\n"
"typedef uint u32;\n"
"\n"
"#define GET_GROUP_IDX groupIdx.x\n"
"#define GET_LOCAL_IDX localIdx.x\n"
"#define GET_GLOBAL_IDX globalIdx.x\n"
"#define GROUP_LDS_BARRIER GroupMemoryBarrierWithGroupSync()\n"
"#define GROUP_MEM_FENCE\n"
"#define DEFAULT_ARGS uint3 globalIdx : SV_DispatchThreadID, uint3 localIdx : SV_GroupThreadID, uint3 groupIdx : SV_GroupID\n"
"#define AtomInc(x) InterlockedAdd(x, 1)\n"
"#define AtomInc1(x, out) InterlockedAdd(x, 1, out)\n"
"\n"
"#define make_uint4 uint4\n"
"#define make_uint2 uint2\n"
"#define make_int2 int2\n"
"\n"
"#define WG_SIZE 64\n"
"\n"
"#define GET_GROUP_SIZE WG_SIZE\n"
"\n"
"\n"
"\n"
"cbuffer CB : register( b0 )\n"
"{\n"
"	int m_n;\n"
"	int m_padding[3];\n"
"};\n"
"\n"
"RWStructuredBuffer<float4> dst : register( u0 );\n"
"StructuredBuffer<float4> src : register( t0 );\n"
"\n"
"[numthreads(WG_SIZE, 1, 1)]\n"
"void Copy1F4Kernel( DEFAULT_ARGS )\n"
"{\n"
"	int gIdx = GET_GLOBAL_IDX;\n"
"\n"
"	if( gIdx < m_n )\n"
"	{\n"
"		float4 a0 = src[gIdx];\n"
"\n"
"		dst[ gIdx ] = a0;\n"
"	}\n"
"}\n"
"\n"
"[numthreads(WG_SIZE, 1, 1)]\n"
"void Copy2F4Kernel( DEFAULT_ARGS )\n"
"{\n"
"	int gIdx = GET_GLOBAL_IDX;\n"
"\n"
"	if( 2*gIdx <= m_n )\n"
"	{\n"
"		float4 a0 = src[gIdx*2+0];\n"
"		float4 a1 = src[gIdx*2+1];\n"
"\n"
"		dst[ gIdx*2+0 ] = a0;\n"
"		dst[ gIdx*2+1 ] = a1;\n"
"	}\n"
"}\n"
"\n"
"[numthreads(WG_SIZE, 1, 1)]\n"
"void Copy4F4Kernel( DEFAULT_ARGS )\n"
"{\n"
"	int gIdx = GET_GLOBAL_IDX;\n"
"\n"
"	if( 4*gIdx <= m_n )\n"
"	{\n"
"		int idx0 = gIdx*4+0;\n"
"		int idx1 = gIdx*4+1;\n"
"		int idx2 = gIdx*4+2;\n"
"		int idx3 = gIdx*4+3;\n"
"\n"
"		float4 a0 = src[idx0];\n"
"		float4 a1 = src[idx1];\n"
"		float4 a2 = src[idx2];\n"
"		float4 a3 = src[idx3];\n"
"\n"
"		dst[ idx0 ] = a0;\n"
"		dst[ idx1 ] = a1;\n"
"		dst[ idx2 ] = a2;\n"
"		dst[ idx3 ] = a3;\n"
"	}\n"
"}\n"
"\n"
"RWStructuredBuffer<float> dstF1 : register( u0 );\n"
"StructuredBuffer<float> srcF1 : register( t0 );\n"
"\n"
"[numthreads(WG_SIZE, 1, 1)]\n"
"void CopyF1Kernel( DEFAULT_ARGS )\n"
"{\n"
"	int gIdx = GET_GLOBAL_IDX;\n"
"\n"
"	if( gIdx < m_n )\n"
"	{\n"
"		float a0 = srcF1[gIdx];\n"
"\n"
"		dstF1[ gIdx ] = a0;\n"
"	}\n"
"\n"
"}\n"
"\n"
"RWStructuredBuffer<float2> dstF2 : register( u0 );\n"
"StructuredBuffer<float2> srcF2 : register( t0 );\n"
"\n"
"[numthreads(WG_SIZE, 1, 1)]\n"
"void CopyF2Kernel( DEFAULT_ARGS )\n"
"{\n"
"	int gIdx = GET_GLOBAL_IDX;\n"
"\n"
"	if( gIdx < m_n )\n"
"	{\n"
"		float2 a0 = srcF2[gIdx];\n"
"\n"
"		dstF2[ gIdx ] = a0;\n"
"	}\n"
"}\n"
;
