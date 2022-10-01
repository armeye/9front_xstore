TEXT repxstore(SB), $-4
	MOVL $3, DX
	MOVL buf+0(FP), DI
	MOVL count+4(FP), CX
	BYTE $0xF3; BYTE $0x0F; BYTE $0xA7; BYTE $0xC0
	RET
