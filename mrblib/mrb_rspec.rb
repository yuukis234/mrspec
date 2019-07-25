class MRSpec

  # describe
  def self.describe (&block)
    block.call if block
  end

  # 説明：context
  def self.context (&block)
    block.call if block
  end

  # 説明：it
  def self.it (&block)
    block.call if block
  end

  # 説明：expect
  # 試す命令が正しいかどうかを試せる
  # 条件文を入れる。
  def self.expect (&block)
    answer = block.call if block
    if answer
      puts "yes!"
    else
      puts "no!"
    end
  end

  # 説明：before
  def self.before
  end

  # 説明:before
  def self.let
  end

  # 実験結果を返してくれる。
  class Experiment
  end

end
