﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace TankFlow
{
    public class Damage
    {
        public string source="";
        public string victim="";
        public int damage;//潜在伤害
        public int type;
        public int victimId;
        public int battleType;
        public int battleId;
        public bool valid = true;
        public bool friend=false;
        
       public string GetDamageType()
        {
            switch (type)
            {
                case 20:
                    return damage.ToString() + "(击毁)";
                case 1:
                    return damage.ToString();
                case 5:
                    return "未击穿";
                case 9:
                    return damage.ToString() + "(暴击)";
                case 17:
                    return "0";
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
                if (int.Parse(mm[7]) == 0)
                    friend = true;
                else
                    friend = false;
                valid = true;
                if (type == 17)
                    valid = false;
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
            if (damage > 0)
            {
                result = fillspace(10,source) + "  ->  " + fillspace(10,victim);
                result = result + "    "+ GetDamageType();
            }
            
            return result;
        }

        public string fillspace(int sum,string source)
        {
            int length = source.Length;
            for (; length < sum; length++)
            {
                source = source + " ";
            }
            if (source.Length > sum)
            {
                source = source.Substring(0, sum - 3);
                source = source + "...";
            }
            return source;
        }
    }
}
