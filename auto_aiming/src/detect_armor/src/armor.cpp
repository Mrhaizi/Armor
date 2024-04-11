#include<detect_armors.h>
Armor::Armor(const LightBar &l_bar,
            const LightBar &r_bar):armor_l_bar(l_bar),armor_r_bar(r_bar) {
            armor_center = cv::Point2f((armor_l_bar.lingt_center.x + armor_r_bar.lingt_center.x) / 2,// 计算装甲板的中心
                            (armor_l_bar.lingt_center.y + armor_r_bar.lingt_center.y)/2);
            armor_width = abs(armor_l_bar.lingt_center.x - armor_r_bar.lingt_center.x);// 计算装甲板的宽度         
            armor_lenth = armor_width * 1.05;      
            // armor_lenth = (armor_l_bar.light_lenth + armor_r_bar.light_lenth) / 2;// 计算装甲板的长度
            left_on_point = cv::Point2f(armor_center.x - armor_width / 2,armor_center.y - armor_lenth / 2 );// 计算装甲板的左上角点，用于绘制矩形        
            type = ArmorType::LARGE;
            if (armor_center.x != 0) {
                left_on = cv::Point2f(armor_center.x - armor_width / 2, armor_center.y - armor_lenth / 2);
                left_under = cv::Point2f(armor_center.x - armor_width / 2, armor_center.y + armor_lenth / 2);
                right_on = cv::Point2f(armor_center.x + armor_width / 2, armor_center.y - armor_lenth / 2);
                right_under = cv::Point2f(armor_center.x + armor_width / 2, armor_center.y + armor_lenth / 2);

            }
            rect = cv::Rect2f(left_on_point.x, left_on_point.y, armor_width, armor_lenth);
}



