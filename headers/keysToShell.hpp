case 1:
	character = NULL;//esc
	return;
case 2:
	if (SHELL_ACTIVE){
	putc(character);}
	 character = '1';
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 3:
	if (SHELL_ACTIVE){ 
	putc(character);}character = '2';
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 4:
	if (SHELL_ACTIVE){ 
	putc(character);}character = '3';
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 5:
	if (SHELL_ACTIVE){ 
	putc(character);}character = '4';
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 6:
	if (SHELL_ACTIVE){ 
	putc(character);}character = '5';
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 7:
	if (SHELL_ACTIVE){ 
	putc(character);} character = '6';
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 8:
	if (SHELL_ACTIVE){ 
	putc(character);}character = '7';
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 9:
	if (SHELL_ACTIVE){ 
	putc(character);}character = '8';
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 10:
	if (SHELL_ACTIVE){ 
	putc(character);}character = '9';
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 11:
	if (SHELL_ACTIVE){ 
	putc(character);}character = '0';
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 12:
	if (SHELL_ACTIVE){ 
	putc(character);}character = '-';
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 13:
	if (SHELL_ACTIVE){ 
    putc(character);}character = '=';
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 14:
    backspace();
	return;
case 15:
    cout("\t");
	
	return;
case 16:
    if (SHELL_ACTIVE){ 
	putc(character);}character = (Shift_BIT ? 'Q' : 'q' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 17:
    if (SHELL_ACTIVE){ 
	putc(character);}character = (Shift_BIT ? 'W' : 'w' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 18:
    if (SHELL_ACTIVE){ 
	putc(character);}character = (Shift_BIT ? 'E' : 'e' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 19:
	if (SHELL_ACTIVE){ 
	putc(character);}character = (Shift_BIT ? 'R' : 'r' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 20:
	if (SHELL_ACTIVE){ 
	putc(character);}character = (Shift_BIT ? 'T' : 't' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 21:
	if (SHELL_ACTIVE){ 
	putc(character);}character = (Shift_BIT ? 'Y' : 'y' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 22:
	if (SHELL_ACTIVE){ 
	putc(character);}character = (Shift_BIT ? 'U' : 'u' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 23:
	if (SHELL_ACTIVE){ 
	putc(character);}character = (Shift_BIT ? 'I' : 'i' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 24:
	if (SHELL_ACTIVE){ 
	putc(character);}character = (Shift_BIT ? 'O' : 'o' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 25:
	if (SHELL_ACTIVE){ 
	putc(character);}character = (Shift_BIT ? 'P' : 'p' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 26:
    cout("[");
	return;
case 27:
    cout("]");
	return;
case 28:
	if (SHELL_ACTIVE){
		SHELL_ACTIVE=(!SHELL_ACTIVE);
		command();
		cout("\n%s[%d]->",PWD,exit_code);
		command_buffer[buffer_ptr]=0;
		SHELL_ACTIVE=(!SHELL_ACTIVE);
	}
	return;
case 29:
    cout("lctrl 29");
	return;
case 30:
	if (SHELL_ACTIVE){ 
	putc(character);}character = (Shift_BIT ? 'A' : 'a' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 31:
	if (SHELL_ACTIVE){
	putc(character);} character = (Shift_BIT ? 'S' : 's' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 32:
	if (SHELL_ACTIVE){ 
	putc(character);}character = (Shift_BIT ? 'D' : 'd' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 33:
	if (SHELL_ACTIVE){ 
	putc(character);}character = (Shift_BIT ? 'F' : 'f' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 34:
	if (SHELL_ACTIVE){ 
	putc(character);}character = (Shift_BIT ? 'G' : 'g' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 35:
	if (SHELL_ACTIVE){ 
	putc(character);}character = (Shift_BIT ? 'H' : 'h' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 36:
	if (SHELL_ACTIVE){ 
	putc(character);}character = (Shift_BIT ? 'J' : 'j' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 37:
	if (SHELL_ACTIVE){ 
	putc(character);}character = (Shift_BIT ? 'K' : 'k' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 38:
	if (SHELL_ACTIVE){ 
	putc(character);}character = (Shift_BIT ? 'L' : 'l' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 39:
	if (SHELL_ACTIVE){ 
	putc(character);}character = ';';
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 40:
	if (SHELL_ACTIVE){ 
	putc(character);}character = '\'';
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 41:
	if (SHELL_ACTIVE){ 
	putc(character);}character = '`';
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 42:
    cout("lShift 42");
	return;

case 43:
	if (SHELL_ACTIVE){ 
	putc(character);}character = '\\';
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 44:
	if (SHELL_ACTIVE){ 
	putc(character);}character = (Shift_BIT ? 'Z' : 'z' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 45:
	if (SHELL_ACTIVE){ 
	putc(character);}character = (Shift_BIT ? 'X' : 'x' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 46:
	if (SHELL_ACTIVE){ 
	putc(character);}character = (Shift_BIT ? 'C' : 'c' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 47:
	if (SHELL_ACTIVE){ 
	putc(character);} character = (Shift_BIT ? 'V' : 'v' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 48:
	if (SHELL_ACTIVE){ 
	putc(character);} character = (Shift_BIT ? 'B' : 'b' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 49:
	if (SHELL_ACTIVE){ 
	putc(character);} character = (Shift_BIT ? 'N' : 'n' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 50:
	if (SHELL_ACTIVE){ 
	putc(character);} character = (Shift_BIT ? 'M' : 'm' );
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 51:
	if (SHELL_ACTIVE){ 
	putc(character);}character = ',';
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 52:
	if (SHELL_ACTIVE){ 
	putc(character);} character = '.';
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
case 53:
	if (SHELL_ACTIVE){ 
	putc(character);} character = '/';
	command_buffer[buffer_ptr] = character;
	buffer_ptr++;
	return;
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
    cout(" ");
	command_buffer[buffer_ptr] = ' ';
	buffer_ptr++;
	return;
case 58:
	Shift_BIT = !Shift_BIT;
	return;
    /*
case 59:
	if (SHELL_ACTIVE){ character = '';
	putc(character);
	return;
case 60:
	character = '';
	putc(character);
	return;
case 61:
	character = '';
	putc(character);
	return;
case 62:
	character = '';
	putc(character);
	return;
case 63:
	character = '';
	putc(character);
	return;
case 64:
	character = '';
	putc(character);
	return;
case 65:
	character = '';
	putc(character);
	return;
case 66:
	character = '';
	putc(character);
	return;
case 67:
	character = '';
	putc(character);
	return;
case 68:
	character = '';
	putc(character);
	return;
case 69:
	character = '';
	putc(character);
	return;
case 70:
	character = '';
	putc(character);
	return;
case 71:
	character = '';
	putc(character);
	return;
case 72:
	character = '';
	putc(character);
	return;
case 73:
	character = '';
	putc(character);
	return;
case 74:
	character = '';
	putc(character);
	return;
case 75:
	character = '';
	putc(character);
	return;
case 76:
	character = '';
	putc(character);
	return;
case 77:
	character = '';
	putc(character);
	return;
case 78:
	character = '';
	putc(character);
	return;
case 79:
	character = '';
	putc(character);
	return;
case 80:
	character = '';
	putc(character);
	return;
case 81:
	character = '';
	putc(character);
	return;
case 82:
	character = '';
	putc(character);
	return;
case 83:
	character = '';
	putc(character);
	return;
case 84:
	character = '';
	putc(character);
	return;
case 85:
	character = '';
	putc(character);
	return;
case 86:
	character = '';
	putc(character);
	return;
case 87:
	character = '';
	putc(character);
	return;
case 88:
	character = '';
	putc(character);
	return;
case 89:
	character = '';
	putc(character);
	return;
case 90:
	character = '';
	putc(character);
	return;
case 91:
	character = '';
	putc(character);
	return;
case 92:
	character = '';
	putc(character);
	return;
case 93:
	character = '';
	putc(character);
	return;
case 94:
	character = '';
	putc(character);
	return;
case 95:
	character = '';
	putc(character);
	return;
case 96:
	character = '';
	putc(character);
	return;
case 97:
	character = '';
	putc(character);
	return;
case 98:
	character = '';
	putc(character);
	return;
case 99:
	character = '';
	putc(character);
	return;
case 100:
	character = '';
	putc(character);
	return;
case 101:
	character = '';
	putc(character);
	return;
case 102:
	character = '';
	putc(character);
	return;
case 103:
	character = '';
	putc(character);
	return;
case 104:
	character = '';
	putc(character);
	return;
case 105:
	character = '';
	putc(character);
	return;
case 106:
	character = '';
	putc(character);
	return;
case 107:
	character = '';
	putc(character);
	return;
case 108:
	character = '';
	putc(character);
	return;
case 109:
	character = '';
	putc(character);
	return;
case 110:
	character = '';
	putc(character);
	return;
case 111:
	character = '';
	putc(character);
	return;
case 112:
	character = '';
	putc(character);
	return;
case 113:
	character = '';
	putc(character);
	return;
case 114:
	character = '';
	putc(character);
	return;
case 115:
	character = '';
	putc(character);
	return;
case 116:
	character = '';
	putc(character);
	return;
case 117:
	character = '';
	putc(character);
	return;
case 118:
	character = '';
	putc(character);
	return;
case 119:
	character = '';
	putc(character);
	return;
case 120:
	character = '';
	putc(character);
	return;
case 121:
	character = '';
	putc(character);
	return;
case 122:
	character = '';
	putc(character);
	return;
case 123:
	character = '';
	putc(character);
	return;
case 124:
	character = '';
	putc(character);
	return;
case 125:
	character = '';
	putc(character);
	return;
case 126:
	character = '';
	putc(character);
	return;
case 127:
	character = '';
	putc(character);
	return;
case 128:
	character = '';
	putc(character);
	return;
case 129:
	character = '';
	putc(character);
	return;
case 130:
	character = '';
	putc(character);
	return;
case 131:
	character = '';
	putc(character);
	return;
case 132:
	character = '';
	putc(character);
	return;
case 133:
	character = '';
	putc(character);
	return;
case 134:
	character = '';
	putc(character);
	return;
case 135:
	character = '';
	putc(character);
	return;
case 136:
	character = '';
	putc(character);
	return;
case 137:
	character = '';
	putc(character);
	return;
case 138:
	character = '';
	putc(character);
	return;
case 139:
	character = '';
	putc(character);
	return;
case 140:
	character = '';
	putc(character);
	return;
case 141:
	character = '';
	putc(character);
	return;
case 142:
	character = '';
	putc(character);
	return;
case 143:
	character = '';
	putc(character);
	return;
case 144:
	character = '';
	putc(character);
	return;
case 145:
	character = '';
	putc(character);
	return;
case 146:
	character = '';
	putc(character);
	return;
case 147:
	character = '';
	putc(character);
	return;
case 148:
	character = '';
	putc(character);
	return;
case 149:
	character = '';
	putc(character);
	return;
case 150:
	character = '';
	putc(character);
	return;
case 151:
	character = '';
	putc(character);
	return;
case 152:
	character = '';
	putc(character);
	return;
case 153:
	character = '';
	putc(character);
	return;
case 154:
	character = '';
	putc(character);
	return;
case 155:
	character = '';
	putc(character);
	return;
case 156:
	character = '';
	putc(character);
	return;
case 157:
	character = '';
	putc(character);
	return;
case 158:
	character = '';
	putc(character);
	return;
case 159:
	character = '';
	putc(character);
	return;
case 160:
	character = '';
	putc(character);
	return;
case 161:
	character = '';
	putc(character);
	return;
case 162:
	character = '';
	putc(character);
	return;
case 163:
	character = '';
	putc(character);
	return;
case 164:
	character = '';
	putc(character);
	return;
case 165:
	character = '';
	putc(character);
	return;
case 166:
	character = '';
	putc(character);
	return;
case 167:
	character = '';
	putc(character);
	return;
case 168:
	character = '';
	putc(character);
	return;
case 169:
	character = '';
	putc(character);
	return;
case 170:
	character = '';
	putc(character);
	return;
case 171:
	character = '';
	putc(character);
	return;
case 172:
	character = '';
	putc(character);
	return;
case 173:
	character = '';
	putc(character);
	return;
case 174:
	character = '';
	putc(character);
	return;
case 175:
	character = '';
	putc(character);
	return;
case 176:
	character = '';
	putc(character);
	return;
case 177:
	character = '';
	putc(character);
	return;
case 178:
	character = '';
	putc(character);
	return;
case 179:
	character = '';
	putc(character);
	return;
case 180:
	character = '';
	putc(character);
	return;
case 181:
	character = '';
	putc(character);
	return;
case 182:
	character = '';
	putc(character);
	return;
case 183:
	character = '';
	putc(character);
	return;
case 184:
	character = '';
	putc(character);
	return;
case 185:
	character = '';
	putc(character);
	return;
case 186:
	character = '';
	putc(character);
	return;
case 187:
	character = '';
	putc(character);
	return;
case 188:
	character = '';
	putc(character);
	return;
case 189:
	character = '';
	putc(character);
	return;
case 190:
	character = '';
	putc(character);
	return;
case 191:
	character = '';
	putc(character);
	return;
case 192:
	character = '';
	putc(character);
	return;
case 193:
	character = '';
	putc(character);
	return;
case 194:
	character = '';
	putc(character);
	return;
case 195:
	character = '';
	putc(character);
	return;
case 196:
	character = '';
	putc(character);
	return;
case 197:
	character = '';
	putc(character);
	return;
case 198:
	character = '';
	putc(character);
	return;
case 199:
	character = '';
	putc(character);
	return;
case 200:
	character = '';
	putc(character);
	return;
case 201:
	character = '';
	putc(character);
	return;
case 202:
	character = '';
	putc(character);
	return;
case 203:
	character = '';
	putc(character);
	return;
case 204:
	character = '';
	putc(character);
	return;
case 205:
	character = '';
	putc(character);
	return;
case 206:
	character = '';
	putc(character);
	return;
case 207:
	character = '';
	putc(character);
	return;
case 208:
	character = '';
	putc(character);
	return;
case 209:
	character = '';
	putc(character);
	return;
case 210:
	character = '';
	putc(character);
	return;
case 211:
	character = '';
	putc(character);
	return;
case 212:
	character = '';
	putc(character);
	return;
case 213:
	character = '';
	putc(character);
	return;
case 214:
	character = '';
	putc(character);
	return;
case 215:
	character = '';
	putc(character);
	return;
case 216:
	character = '';
	putc(character);
	return;
case 217:
	character = '';
	putc(character);
	return;
case 218:
	character = '';
	putc(character);
	return;
case 219:
	character = '';
	putc(character);
	return;
case 220:
	character = '';
	putc(character);
	return;
case 221:
	character = '';
	putc(character);
	return;
case 222:
	character = '';
	putc(character);
	return;
case 223:
	character = '';
	putc(character);
	return;
case 224:
	character = '';
	putc(character);
	return;
case 225:
	character = '';
	putc(character);
	return;
case 226:
	character = '';
	putc(character);
	return;
case 227:
	character = '';
	putc(character);
	return;
case 228:
	character = '';
	putc(character);
	return;
case 229:
	character = '';
	putc(character);
	return;
case 230:
	character = '';
	putc(character);
	return;
case 231:
	character = '';
	putc(character);
	return;
case 232:
	character = '';
	putc(character);
	return;
case 233:
	character = '';
	putc(character);
	return;
case 234:
	character = '';
	putc(character);
	return;
case 235:
	character = '';
	putc(character);
	return;
case 236:
	character = '';
	putc(character);
	return;
case 237:
	character = '';
	putc(character);
	return;
case 238:
	character = '';
	putc(character);
	return;
case 239:
	character = '';
	putc(character);
	return;
case 240:
	character = '';
	putc(character);
	return;
case 241:
	character = '';
	putc(character);
	return;
case 242:
	character = '';
	putc(character);
	return;
case 243:
	character = '';
	putc(character);
	return;
case 244:
	character = '';
	putc(character);
	return;
case 245:
	character = '';
	putc(character);
	return;
case 246:
	character = '';
	putc(character);
	return;
case 247:
	character = '';
	putc(character);
	return;
case 248:
	character = '';
	putc(character);
	return;
case 249:
	character = '';
	putc(character);
	return;
case 250:
	character = '';
	putc(character);
	return;
case 251:
	character = '';
	putc(character);
	return;
case 252:
	character = '';
	putc(character);
	return;
case 253:
	character = '';
	putc(character);
	return;
case 254:
	character = '';
	putc(character);
	return;
case 255:
	character = '';
	putc(character);
	return;
*/