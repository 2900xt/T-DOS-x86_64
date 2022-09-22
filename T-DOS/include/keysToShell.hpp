case 1:
	character = 0;//esc
	return;
case 2:
	character = '1';
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){
		command_buffer[buffer_ptr] = character;
	buffer_ptr++;}else{ProgramBuffer[PBC++] = character;return;}
	
	
	return;
case 3:
character = '2';
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){
	command_buffer[buffer_ptr] = character;
buffer_ptr++;}else{ProgramBuffer[PBC++] = character;return;}
return;


case 4:
character = '3';
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 5:
character = '4';
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 6:
character = '5';
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 7:
character = '6';
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 8:
character = '7';
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 9:
character = '8';
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 10:
	if (TTY_ACTIVE){
		writeChar(character);
	}
character = '9';
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 11:
character = '0';
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 12:
character = '-';
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 13:
character = (Shift_BIT ? '+' : '=' );
	if (TTY_ACTIVE){
		writeChar(character);
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
		writeChar(character);
	}

    if (SHELL_ACTIVE){ 
	
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 17:
character = (Shift_BIT ? 'W' : 'w' );
	if (TTY_ACTIVE){
		writeChar(character);
	}
    if (SHELL_ACTIVE){ 
	
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 18:
character = (Shift_BIT ? 'E' : 'e' );
	if (TTY_ACTIVE){
		writeChar(character);
	}
    if (SHELL_ACTIVE){ 
	
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 19:
character = (Shift_BIT ? 'R' : 'r' );
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 20:
character = (Shift_BIT ? 'T' : 't' );
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 21:
character = (Shift_BIT ? 'Y' : 'y' );
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 22:
character = (Shift_BIT ? 'U' : 'u' );
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 23:
character = (Shift_BIT ? 'I' : 'i' );
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 24:
character = (Shift_BIT ? 'O' : 'o' );
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 25:
character = (Shift_BIT ? 'P' : 'p' );
	if (TTY_ACTIVE){
		writeChar(character);
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
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 31:
character = (Shift_BIT ? 'S' : 's' );
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){
	 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 32:
character = (Shift_BIT ? 'D' : 'd' );
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 33:
	character = (Shift_BIT ? 'F' : 'f' );
		if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 34:
character = (Shift_BIT ? 'G' : 'g' );
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 35:
character = (Shift_BIT ? 'H' : 'h' );
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 36:
character = (Shift_BIT ? 'J' : 'j' );
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 37:
character = (Shift_BIT ? 'K' : 'k' );
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 38:
character = (Shift_BIT ? 'L' : 'l' );
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 39:
character = ';';
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 40:
character = '\'';
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 41:
character = '`';
	if (TTY_ACTIVE){
		writeChar(character);
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
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 44:
character = (Shift_BIT ? 'Z' : 'z' );
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 45:
character = (Shift_BIT ? 'X' : 'x' );
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 46:
character = (Shift_BIT ? 'C' : 'c' );
	if (TTY_ACTIVE){
		writeChar(character);
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
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 49:
character = (Shift_BIT ? 'N' : 'n' );
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 50:
character = (Shift_BIT ? 'M' : 'm' );
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 51:
character = ',';
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 52:
character = '.';
	if (TTY_ACTIVE){
		writeChar(character);
	}
	if (SHELL_ACTIVE){ 
	 
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;}else{ProgramBuffer[PBC++] = character;return;}
case 53:
character = '/';
	if (TTY_ACTIVE){
		writeChar(character);
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
	writeChar(character);
	return;
case 61:
	character = '';
	writeChar(character);
	return;
case 62:
	character = '';
	writeChar(character);
	return;
case 63:
	character = '';
	writeChar(character);
	return;
case 64:
	character = '';
	writeChar(character);
	return;
case 65:
	character = '';
	writeChar(character);
	return;
case 66:
	character = '';
	writeChar(character);
	return;
case 67:
	character = '';
	writeChar(character);
	return;
case 68:
	character = '';
	writeChar(character);
	return;
case 69:
	character = '';
	writeChar(character);
	return;
case 70:
	character = '';
	writeChar(character);
	return;
case 71:
	character = '';
	writeChar(character);
	return;
case 72:
	character = '';
	writeChar(character);
	return;
case 73:
	character = '';
	writeChar(character);
	return;
case 74:
	character = '';
	writeChar(character);
	return;
case 75:
	character = '';
	writeChar(character);
	return;
case 76:
	character = '';
	writeChar(character);
	return;
case 77:
	character = '';
	writeChar(character);
	return;
case 78:
	character = '';
	writeChar(character);
	return;
case 79:
	character = '';
	writeChar(character);
	return;
case 80:
	character = '';
	writeChar(character);
	return;
case 81:
	character = '';
	writeChar(character);
	return;
case 82:
	character = '';
	writeChar(character);
	return;
case 83:
	character = '';
	writeChar(character);
	return;
case 84:
	character = '';
	writeChar(character);
	return;
case 85:
	character = '';
	writeChar(character);
	return;
case 86:
	character = '';
	writeChar(character);
	return;
case 87:
	character = '';
	writeChar(character);
	return;
case 88:
	character = '';
	writeChar(character);
	return;
case 89:
	character = '';
	writeChar(character);
	return;
case 90:
	character = '';
	writeChar(character);
	return;
case 91:
	character = '';
	writeChar(character);
	return;
case 92:
	character = '';
	writeChar(character);
	return;
case 93:
	character = '';
	writeChar(character);
	return;
case 94:
	character = '';
	writeChar(character);
	return;
case 95:
	character = '';
	writeChar(character);
	return;
case 96:
	character = '';
	writeChar(character);
	return;
case 97:
	character = '';
	writeChar(character);
	return;
case 98:
	character = '';
	writeChar(character);
	return;
case 99:
	character = '';
	writeChar(character);
	return;
case 100:
	character = '';
	writeChar(character);
	return;
case 101:
	character = '';
	writeChar(character);
	return;
case 102:
	character = '';
	writeChar(character);
	return;
case 103:
	character = '';
	writeChar(character);
	return;
case 104:
	character = '';
	writeChar(character);
	return;
case 105:
	character = '';
	writeChar(character);
	return;
case 106:
	character = '';
	writeChar(character);
	return;
case 107:
	character = '';
	writeChar(character);
	return;
case 108:
	character = '';
	writeChar(character);
	return;
case 109:
	character = '';
	writeChar(character);
	return;
case 110:
	character = '';
	writeChar(character);
	return;
case 111:
	character = '';
	writeChar(character);
	return;
case 112:
	character = '';
	writeChar(character);
	return;
case 113:
	character = '';
	writeChar(character);
	return;
case 114:
	character = '';
	writeChar(character);
	return;
case 115:
	character = '';
	writeChar(character);
	return;
case 116:
	character = '';
	writeChar(character);
	return;
case 117:
	character = '';
	writeChar(character);
	return;
case 118:
	character = '';
	writeChar(character);
	return;
case 119:
	character = '';
	writeChar(character);
	return;
case 120:
	character = '';
	writeChar(character);
	return;
case 121:
	character = '';
	writeChar(character);
	return;
case 122:
	character = '';
	writeChar(character);
	return;
case 123:
	character = '';
	writeChar(character);
	return;
case 124:
	character = '';
	writeChar(character);
	return;
case 125:
	character = '';
	writeChar(character);
	return;
case 126:
	character = '';
	writeChar(character);
	return;
case 127:
	character = '';
	writeChar(character);
	return;
case 128:
	character = '';
	writeChar(character);
	return;
case 129:
	character = '';
	writeChar(character);
	return;
case 130:
	character = '';
	writeChar(character);
	return;
case 131:
	character = '';
	writeChar(character);
	return;
case 132:
	character = '';
	writeChar(character);
	return;
case 133:
	character = '';
	writeChar(character);
	return;
case 134:
	character = '';
	writeChar(character);
	return;
case 135:
	character = '';
	writeChar(character);
	return;
case 136:
	character = '';
	writeChar(character);
	return;
case 137:
	character = '';
	writeChar(character);
	return;
case 138:
	character = '';
	writeChar(character);
	return;
case 139:
	character = '';
	writeChar(character);
	return;
case 140:
	character = '';
	writeChar(character);
	return;
case 141:
	character = '';
	writeChar(character);
	return;
case 142:
	character = '';
	writeChar(character);
	return;
case 143:
	character = '';
	writeChar(character);
	return;
case 144:
	character = '';
	writeChar(character);
	return;
case 145:
	character = '';
	writeChar(character);
	return;
case 146:
	character = '';
	writeChar(character);
	return;
case 147:
	character = '';
	writeChar(character);
	return;
case 148:
	character = '';
	writeChar(character);
	return;
case 149:
	character = '';
	writeChar(character);
	return;
case 150:
	character = '';
	writeChar(character);
	return;
case 151:
	character = '';
	writeChar(character);
	return;
case 152:
	character = '';
	writeChar(character);
	return;
case 153:
	character = '';
	writeChar(character);
	return;
case 154:
	character = '';
	writeChar(character);
	return;
case 155:
	character = '';
	writeChar(character);
	return;
case 156:
	character = '';
	writeChar(character);
	return;
case 157:
	character = '';
	writeChar(character);
	return;
case 158:
	character = '';
	writeChar(character);
	return;
case 159:
	character = '';
	writeChar(character);
	return;
case 160:
	character = '';
	writeChar(character);
	return;
case 161:
	character = '';
	writeChar(character);
	return;
case 162:
	character = '';
	writeChar(character);
	return;
case 163:
	character = '';
	writeChar(character);
	return;
case 164:
	character = '';
	writeChar(character);
	return;
case 165:
	character = '';
	writeChar(character);
	return;
case 166:
	character = '';
	writeChar(character);
	return;
case 167:
	character = '';
	writeChar(character);
	return;
case 168:
	character = '';
	writeChar(character);
	return;
case 169:
	character = '';
	writeChar(character);
	return;
case 170:
	character = '';
	writeChar(character);
	return;
case 171:
	character = '';
	writeChar(character);
	return;
case 172:
	character = '';
	writeChar(character);
	return;
case 173:
	character = '';
	writeChar(character);
	return;
case 174:
	character = '';
	writeChar(character);
	return;
case 175:
	character = '';
	writeChar(character);
	return;
case 176:
	character = '';
	writeChar(character);
	return;
case 177:
	character = '';
	writeChar(character);
	return;
case 178:
	character = '';
	writeChar(character);
	return;
case 179:
	character = '';
	writeChar(character);
	return;
case 180:
	character = '';
	writeChar(character);
	return;
case 181:
	character = '';
	writeChar(character);
	return;
case 182:
	character = '';
	writeChar(character);
	return;
case 183:
	character = '';
	writeChar(character);
	return;
case 184:
	character = '';
	writeChar(character);
	return;
case 185:
	character = '';
	writeChar(character);
	return;
case 186:
	character = '';
	writeChar(character);
	return;
case 187:
	character = '';
	writeChar(character);
	return;
case 188:
	character = '';
	writeChar(character);
	return;
case 189:
	character = '';
	writeChar(character);
	return;
case 190:
	character = '';
	writeChar(character);
	return;
case 191:
	character = '';
	writeChar(character);
	return;
case 192:
	character = '';
	writeChar(character);
	return;
case 193:
	character = '';
	writeChar(character);
	return;
case 194:
	character = '';
	writeChar(character);
	return;
case 195:
	character = '';
	writeChar(character);
	return;
case 196:
	character = '';
	writeChar(character);
	return;
case 197:
	character = '';
	writeChar(character);
	return;
case 198:
	character = '';
	writeChar(character);
	return;
case 199:
	character = '';
	writeChar(character);
	return;
case 200:
	character = '';
	writeChar(character);
	return;
case 201:
	character = '';
	writeChar(character);
	return;
case 202:
	character = '';
	writeChar(character);
	return;
case 203:
	character = '';
	writeChar(character);
	return;
case 204:
	character = '';
	writeChar(character);
	return;
case 205:
	character = '';
	writeChar(character);
	return;
case 206:
	character = '';
	writeChar(character);
	return;
case 207:
	character = '';
	writeChar(character);
	return;
case 208:
	character = '';
	writeChar(character);
	return;
case 209:
	character = '';
	writeChar(character);
	return;
case 210:
	character = '';
	writeChar(character);
	return;
case 211:
	character = '';
	writeChar(character);
	return;
case 212:
	character = '';
	writeChar(character);
	return;
case 213:
	character = '';
	writeChar(character);
	return;
case 214:
	character = '';
	writeChar(character);
	return;
case 215:
	character = '';
	writeChar(character);
	return;
case 216:
	character = '';
	writeChar(character);
	return;
case 217:
	character = '';
	writeChar(character);
	return;
case 218:
	character = '';
	writeChar(character);
	return;
case 219:
	character = '';
	writeChar(character);
	return;
case 220:
	character = '';
	writeChar(character);
	return;
case 221:
	character = '';
	writeChar(character);
	return;
case 222:
	character = '';
	writeChar(character);
	return;
case 223:
	character = '';
	writeChar(character);
	return;
case 224:
	character = '';
	writeChar(character);
	return;
case 225:
	character = '';
	writeChar(character);
	return;
case 226:
	character = '';
	writeChar(character);
	return;
case 227:
	character = '';
	writeChar(character);
	return;
case 228:
	character = '';
	writeChar(character);
	return;
case 229:
	character = '';
	writeChar(character);
	return;
case 230:
	character = '';
	writeChar(character);
	return;
case 231:
	character = '';
	writeChar(character);
	return;
case 232:
	character = '';
	writeChar(character);
	return;
case 233:
	character = '';
	writeChar(character);
	return;
case 234:
	character = '';
	writeChar(character);
	return;
case 235:
	character = '';
	writeChar(character);
	return;
case 236:
	character = '';
	writeChar(character);
	return;
case 237:
	character = '';
	writeChar(character);
	return;
case 238:
	character = '';
	writeChar(character);
	return;
case 239:
	character = '';
	writeChar(character);
	return;
case 240:
	character = '';
	writeChar(character);
	return;
case 241:
	character = '';
	writeChar(character);
	return;
case 242:
	character = '';
	writeChar(character);
	return;
case 243:
	character = '';
	writeChar(character);
	return;
case 244:
	character = '';
	writeChar(character);
	return;
case 245:
	character = '';
	writeChar(character);
	return;
case 246:
	character = '';
	writeChar(character);
	return;
case 247:
	character = '';
	writeChar(character);
	return;
case 248:
	character = '';
	writeChar(character);
	return;
case 249:
	character = '';
	writeChar(character);
	return;
case 250:
	character = '';
	writeChar(character);
	return;
case 251:
	character = '';
	writeChar(character);
	return;
case 252:
	character = '';
	writeChar(character);
	return;
case 253:
	character = '';
	writeChar(character);
	return;
case 254:
	character = '';
	writeChar(character);
	return;
case 255:
	character = '';
	writeChar(character);
	return;
*/