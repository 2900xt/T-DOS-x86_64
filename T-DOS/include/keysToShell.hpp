case 1:
	character = 0;//esc
	return;
case 2:
	character = '1';
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){
		command_buffer[buffer_ptr] = character;
	buffer_ptr++;}else{ProgramBuffer[PBC++] = character;return;}
	
	
	return;
case 3:
character = '2';
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	putString(&character,15);
	command_buffer[buffer_ptr] = character;
buffer_ptr++;}else{ProgramBuffer[PBC++] = character;return;}
return;


case 4:
character = '3';
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 5:
character = '4';
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 6:
character = '5';
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 7:
character = '6';
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 8:
character = '7';
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 9:
character = '8';
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 10:
	if (TTY_ACTIVE){
		putString(&character,15);
	}
character = '9';
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 11:
character = '0';
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 12:
character = '-';
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 13:
character = (Shift_BIT ? '+' : '=' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
    }
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 14:
if (TTY_ACTIVE){
    backspace();}
	return;
case 15:
    cout("\t");
	return;
case 16:
character = (Shift_BIT ? 'Q' : 'q' );
	if (TTY_ACTIVE){
		putChar(fonts[character],g_ScreenX,g_ScreenY+8,15);
	}

    if (SHELL_ACTIVE){ 
	
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 17:
character = (Shift_BIT ? 'W' : 'w' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
    if (SHELL_ACTIVE){ 
	
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 18:
character = (Shift_BIT ? 'E' : 'e' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
    if (SHELL_ACTIVE){ 
	
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 19:
character = (Shift_BIT ? 'R' : 'r' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 20:
character = (Shift_BIT ? 'T' : 't' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 21:
character = (Shift_BIT ? 'Y' : 'y' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 22:
character = (Shift_BIT ? 'U' : 'u' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 23:
character = (Shift_BIT ? 'I' : 'i' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 24:
character = (Shift_BIT ? 'O' : 'o' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 25:
character = (Shift_BIT ? 'P' : 'p' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 26:
    cout("[");
	return;
case 27:
    cout("]");
	return;
case 28:
	if (SHELL_ACTIVE){
		SHELL_ACTIVE=(!SHELL_ACTIVE);
	}
	else if(!programEnter){
		programEnter = 1;
	}
	return;
case 29:
    cout("lctrl 29");
	return;
case 30:
character = (Shift_BIT ? 'A' : 'a' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 31:
character = (Shift_BIT ? 'S' : 's' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){
	 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 32:
character = (Shift_BIT ? 'D' : 'd' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 33:
	character = (Shift_BIT ? 'F' : 'f' );
		if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 34:
character = (Shift_BIT ? 'G' : 'g' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 35:
character = (Shift_BIT ? 'H' : 'h' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 36:
character = (Shift_BIT ? 'J' : 'j' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 37:
character = (Shift_BIT ? 'K' : 'k' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 38:
character = (Shift_BIT ? 'L' : 'l' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 39:
character = ';';
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 40:
character = '\'';
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 41:
character = '`';
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 42:
    cout("lShift 42");
	return;

case 43:
character = '\\';
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 44:
character = (Shift_BIT ? 'Z' : 'z' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 45:
character = (Shift_BIT ? 'X' : 'x' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 46:
character = (Shift_BIT ? 'C' : 'c' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 47:
character = (Shift_BIT ? 'V' : 'v' );
	if (SHELL_ACTIVE){ 
	 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 48:
character = (Shift_BIT ? 'B' : 'b' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 49:
character = (Shift_BIT ? 'N' : 'n' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 50:
character = (Shift_BIT ? 'M' : 'm' );
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 51:
character = ',';
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 52:
character = '.';
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 53:
character = '/';
	if (TTY_ACTIVE){
		putString(&character,15);
	}
	if (SHELL_ACTIVE){ 
	 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 54:
    cout("rshift 54");
	return;
case 55:
    cout("keypad 55");
	return;
case 56:
    cout("left alt 56");
	return;
case 57:
if (SHELL_ACTIVE){
    cout(" ");
	command_buffer[buffer_ptr] = ' ';
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 58:
	Shift_BIT = !Shift_BIT;
	return;
    /*
case 59:
	if (SHELL_ACTIVE){ character = '';
	
	return;
case 60:
	character = '';
	putString(&character,15);
	return;
case 61:
	character = '';
	putString(&character,15);
	return;
case 62:
	character = '';
	putString(&character,15);
	return;
case 63:
	character = '';
	putString(&character,15);
	return;
case 64:
	character = '';
	putString(&character,15);
	return;
case 65:
	character = '';
	putString(&character,15);
	return;
case 66:
	character = '';
	putString(&character,15);
	return;
case 67:
	character = '';
	putString(&character,15);
	return;
case 68:
	character = '';
	putString(&character,15);
	return;
case 69:
	character = '';
	putString(&character,15);
	return;
case 70:
	character = '';
	putString(&character,15);
	return;
case 71:
	character = '';
	putString(&character,15);
	return;
case 72:
	character = '';
	putString(&character,15);
	return;
case 73:
	character = '';
	putString(&character,15);
	return;
case 74:
	character = '';
	putString(&character,15);
	return;
case 75:
	character = '';
	putString(&character,15);
	return;
case 76:
	character = '';
	putString(&character,15);
	return;
case 77:
	character = '';
	putString(&character,15);
	return;
case 78:
	character = '';
	putString(&character,15);
	return;
case 79:
	character = '';
	putString(&character,15);
	return;
case 80:
	character = '';
	putString(&character,15);
	return;
case 81:
	character = '';
	putString(&character,15);
	return;
case 82:
	character = '';
	putString(&character,15);
	return;
case 83:
	character = '';
	putString(&character,15);
	return;
case 84:
	character = '';
	putString(&character,15);
	return;
case 85:
	character = '';
	putString(&character,15);
	return;
case 86:
	character = '';
	putString(&character,15);
	return;
case 87:
	character = '';
	putString(&character,15);
	return;
case 88:
	character = '';
	putString(&character,15);
	return;
case 89:
	character = '';
	putString(&character,15);
	return;
case 90:
	character = '';
	putString(&character,15);
	return;
case 91:
	character = '';
	putString(&character,15);
	return;
case 92:
	character = '';
	putString(&character,15);
	return;
case 93:
	character = '';
	putString(&character,15);
	return;
case 94:
	character = '';
	putString(&character,15);
	return;
case 95:
	character = '';
	putString(&character,15);
	return;
case 96:
	character = '';
	putString(&character,15);
	return;
case 97:
	character = '';
	putString(&character,15);
	return;
case 98:
	character = '';
	putString(&character,15);
	return;
case 99:
	character = '';
	putString(&character,15);
	return;
case 100:
	character = '';
	putString(&character,15);
	return;
case 101:
	character = '';
	putString(&character,15);
	return;
case 102:
	character = '';
	putString(&character,15);
	return;
case 103:
	character = '';
	putString(&character,15);
	return;
case 104:
	character = '';
	putString(&character,15);
	return;
case 105:
	character = '';
	putString(&character,15);
	return;
case 106:
	character = '';
	putString(&character,15);
	return;
case 107:
	character = '';
	putString(&character,15);
	return;
case 108:
	character = '';
	putString(&character,15);
	return;
case 109:
	character = '';
	putString(&character,15);
	return;
case 110:
	character = '';
	putString(&character,15);
	return;
case 111:
	character = '';
	putString(&character,15);
	return;
case 112:
	character = '';
	putString(&character,15);
	return;
case 113:
	character = '';
	putString(&character,15);
	return;
case 114:
	character = '';
	putString(&character,15);
	return;
case 115:
	character = '';
	putString(&character,15);
	return;
case 116:
	character = '';
	putString(&character,15);
	return;
case 117:
	character = '';
	putString(&character,15);
	return;
case 118:
	character = '';
	putString(&character,15);
	return;
case 119:
	character = '';
	putString(&character,15);
	return;
case 120:
	character = '';
	putString(&character,15);
	return;
case 121:
	character = '';
	putString(&character,15);
	return;
case 122:
	character = '';
	putString(&character,15);
	return;
case 123:
	character = '';
	putString(&character,15);
	return;
case 124:
	character = '';
	putString(&character,15);
	return;
case 125:
	character = '';
	putString(&character,15);
	return;
case 126:
	character = '';
	putString(&character,15);
	return;
case 127:
	character = '';
	putString(&character,15);
	return;
case 128:
	character = '';
	putString(&character,15);
	return;
case 129:
	character = '';
	putString(&character,15);
	return;
case 130:
	character = '';
	putString(&character,15);
	return;
case 131:
	character = '';
	putString(&character,15);
	return;
case 132:
	character = '';
	putString(&character,15);
	return;
case 133:
	character = '';
	putString(&character,15);
	return;
case 134:
	character = '';
	putString(&character,15);
	return;
case 135:
	character = '';
	putString(&character,15);
	return;
case 136:
	character = '';
	putString(&character,15);
	return;
case 137:
	character = '';
	putString(&character,15);
	return;
case 138:
	character = '';
	putString(&character,15);
	return;
case 139:
	character = '';
	putString(&character,15);
	return;
case 140:
	character = '';
	putString(&character,15);
	return;
case 141:
	character = '';
	putString(&character,15);
	return;
case 142:
	character = '';
	putString(&character,15);
	return;
case 143:
	character = '';
	putString(&character,15);
	return;
case 144:
	character = '';
	putString(&character,15);
	return;
case 145:
	character = '';
	putString(&character,15);
	return;
case 146:
	character = '';
	putString(&character,15);
	return;
case 147:
	character = '';
	putString(&character,15);
	return;
case 148:
	character = '';
	putString(&character,15);
	return;
case 149:
	character = '';
	putString(&character,15);
	return;
case 150:
	character = '';
	putString(&character,15);
	return;
case 151:
	character = '';
	putString(&character,15);
	return;
case 152:
	character = '';
	putString(&character,15);
	return;
case 153:
	character = '';
	putString(&character,15);
	return;
case 154:
	character = '';
	putString(&character,15);
	return;
case 155:
	character = '';
	putString(&character,15);
	return;
case 156:
	character = '';
	putString(&character,15);
	return;
case 157:
	character = '';
	putString(&character,15);
	return;
case 158:
	character = '';
	putString(&character,15);
	return;
case 159:
	character = '';
	putString(&character,15);
	return;
case 160:
	character = '';
	putString(&character,15);
	return;
case 161:
	character = '';
	putString(&character,15);
	return;
case 162:
	character = '';
	putString(&character,15);
	return;
case 163:
	character = '';
	putString(&character,15);
	return;
case 164:
	character = '';
	putString(&character,15);
	return;
case 165:
	character = '';
	putString(&character,15);
	return;
case 166:
	character = '';
	putString(&character,15);
	return;
case 167:
	character = '';
	putString(&character,15);
	return;
case 168:
	character = '';
	putString(&character,15);
	return;
case 169:
	character = '';
	putString(&character,15);
	return;
case 170:
	character = '';
	putString(&character,15);
	return;
case 171:
	character = '';
	putString(&character,15);
	return;
case 172:
	character = '';
	putString(&character,15);
	return;
case 173:
	character = '';
	putString(&character,15);
	return;
case 174:
	character = '';
	putString(&character,15);
	return;
case 175:
	character = '';
	putString(&character,15);
	return;
case 176:
	character = '';
	putString(&character,15);
	return;
case 177:
	character = '';
	putString(&character,15);
	return;
case 178:
	character = '';
	putString(&character,15);
	return;
case 179:
	character = '';
	putString(&character,15);
	return;
case 180:
	character = '';
	putString(&character,15);
	return;
case 181:
	character = '';
	putString(&character,15);
	return;
case 182:
	character = '';
	putString(&character,15);
	return;
case 183:
	character = '';
	putString(&character,15);
	return;
case 184:
	character = '';
	putString(&character,15);
	return;
case 185:
	character = '';
	putString(&character,15);
	return;
case 186:
	character = '';
	putString(&character,15);
	return;
case 187:
	character = '';
	putString(&character,15);
	return;
case 188:
	character = '';
	putString(&character,15);
	return;
case 189:
	character = '';
	putString(&character,15);
	return;
case 190:
	character = '';
	putString(&character,15);
	return;
case 191:
	character = '';
	putString(&character,15);
	return;
case 192:
	character = '';
	putString(&character,15);
	return;
case 193:
	character = '';
	putString(&character,15);
	return;
case 194:
	character = '';
	putString(&character,15);
	return;
case 195:
	character = '';
	putString(&character,15);
	return;
case 196:
	character = '';
	putString(&character,15);
	return;
case 197:
	character = '';
	putString(&character,15);
	return;
case 198:
	character = '';
	putString(&character,15);
	return;
case 199:
	character = '';
	putString(&character,15);
	return;
case 200:
	character = '';
	putString(&character,15);
	return;
case 201:
	character = '';
	putString(&character,15);
	return;
case 202:
	character = '';
	putString(&character,15);
	return;
case 203:
	character = '';
	putString(&character,15);
	return;
case 204:
	character = '';
	putString(&character,15);
	return;
case 205:
	character = '';
	putString(&character,15);
	return;
case 206:
	character = '';
	putString(&character,15);
	return;
case 207:
	character = '';
	putString(&character,15);
	return;
case 208:
	character = '';
	putString(&character,15);
	return;
case 209:
	character = '';
	putString(&character,15);
	return;
case 210:
	character = '';
	putString(&character,15);
	return;
case 211:
	character = '';
	putString(&character,15);
	return;
case 212:
	character = '';
	putString(&character,15);
	return;
case 213:
	character = '';
	putString(&character,15);
	return;
case 214:
	character = '';
	putString(&character,15);
	return;
case 215:
	character = '';
	putString(&character,15);
	return;
case 216:
	character = '';
	putString(&character,15);
	return;
case 217:
	character = '';
	putString(&character,15);
	return;
case 218:
	character = '';
	putString(&character,15);
	return;
case 219:
	character = '';
	putString(&character,15);
	return;
case 220:
	character = '';
	putString(&character,15);
	return;
case 221:
	character = '';
	putString(&character,15);
	return;
case 222:
	character = '';
	putString(&character,15);
	return;
case 223:
	character = '';
	putString(&character,15);
	return;
case 224:
	character = '';
	putString(&character,15);
	return;
case 225:
	character = '';
	putString(&character,15);
	return;
case 226:
	character = '';
	putString(&character,15);
	return;
case 227:
	character = '';
	putString(&character,15);
	return;
case 228:
	character = '';
	putString(&character,15);
	return;
case 229:
	character = '';
	putString(&character,15);
	return;
case 230:
	character = '';
	putString(&character,15);
	return;
case 231:
	character = '';
	putString(&character,15);
	return;
case 232:
	character = '';
	putString(&character,15);
	return;
case 233:
	character = '';
	putString(&character,15);
	return;
case 234:
	character = '';
	putString(&character,15);
	return;
case 235:
	character = '';
	putString(&character,15);
	return;
case 236:
	character = '';
	putString(&character,15);
	return;
case 237:
	character = '';
	putString(&character,15);
	return;
case 238:
	character = '';
	putString(&character,15);
	return;
case 239:
	character = '';
	putString(&character,15);
	return;
case 240:
	character = '';
	putString(&character,15);
	return;
case 241:
	character = '';
	putString(&character,15);
	return;
case 242:
	character = '';
	putString(&character,15);
	return;
case 243:
	character = '';
	putString(&character,15);
	return;
case 244:
	character = '';
	putString(&character,15);
	return;
case 245:
	character = '';
	putString(&character,15);
	return;
case 246:
	character = '';
	putString(&character,15);
	return;
case 247:
	character = '';
	putString(&character,15);
	return;
case 248:
	character = '';
	putString(&character,15);
	return;
case 249:
	character = '';
	putString(&character,15);
	return;
case 250:
	character = '';
	putString(&character,15);
	return;
case 251:
	character = '';
	putString(&character,15);
	return;
case 252:
	character = '';
	putString(&character,15);
	return;
case 253:
	character = '';
	putString(&character,15);
	return;
case 254:
	character = '';
	putString(&character,15);
	return;
case 255:
	character = '';
	putString(&character,15);
	return;
*/