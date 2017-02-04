if OS.linux? or OS.mac?
  require 'mail'
end





def sendFinishEmail(_cmd)

  if OS.linux? or OS.mac?

    options = { :address              => "smtp.live.com",
                :port                 => 25,
                :user_name            => 'robbean53@hotmail.com',
                :password             => 'Gandalf07',
                :authentication       => 'plain',
                :enable_starttls_auto => true  }

    Mail.defaults do
      delivery_method :smtp, options
    end

    msg = "Finished #{_cmd} at #{Time.new.inspect}"

    Mail.deliver do
      to 'robcbean@gmail.com'
      from 'robbean53@hotmail.com'
      subject msg
      body ''
    end

  end
end