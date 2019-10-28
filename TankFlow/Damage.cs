using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TankFlow
{
    class Damage
    {
        public string source;
        public string victim;
        public int damage;//潜在伤害
        public int type;
        public int victimId;
        public int battleType;
        public int battleId;
        public bool valid = true;
        
        string GetDamageType()
        {
            switch (type)
            {
                case 20:
                    return damage.ToString() + "    (击毁)";
                case 1:
                    return "普通伤害";
                case 5:
                    return "未击穿";
                case 9:
                    return damage.ToString() + "    (暴击)";
                case 17:
                    return "友军伤害";
                default:
                    return "";
            }
        }

        string GetBattleType()
        {
            switch (battleType){
                case 0:
                    return "标准模式";
                case 1:
                    return "复活模式";
                case 9:
                    return "天梯模式";
                default:
                    return "";
            }
        }

        public Damage(string s)
        {
            try
            {
                string[] mm = s.Split(',');
                source = mm[0];
                victim = mm[1];
                damage = int.Parse(mm[2]);
                type = int.Parse(mm[3]);
                victimId = int.Parse(mm[4]);
                battleType = int.Parse(mm[5]);
                battleId = int.Parse(mm[6]);
                valid = true;
            }
            catch(Exception e)
            {
                valid = false;
                Console.WriteLine(e.Message);
                Console.WriteLine("出错的字符串是：" + s);
            }
        }

        public string parse()
        {
            string result = "";
            if (type == 17)
                return "";
            if (damage > 0)
            {
                result = source + "->" + victim;
                result = fillspace(20, result);
                if (type == 5 || type == 20 || type == 9)
                    result = result + GetDamageType();
                else
                {
                    result = result + damage.ToString();
                }
            }
            
            return result;
        }

        private string fillspace(int sum,string source)
        {
            int length = source.Length;
            for (; length < sum; length++)
            {
                source = source + " ";
            }
            return source;
        }
    }
}
